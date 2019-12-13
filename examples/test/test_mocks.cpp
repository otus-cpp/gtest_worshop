#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include <memory>

using testing::AtLeast;
using testing::AtMost;
using testing::Return;
using testing::_;

// Some connection interface
struct IDataBaseConnection {
    virtual bool login(
        const std::string& user,
        const std::string& password) = 0;

    virtual bool logout() = 0;
};

// Some implementation of working with DB
struct DataBase {
    DataBase(
        IDataBaseConnection* connection,
        const std::string& user,
        const std::string& password
    ) : m_connection{connection}
        , m_user{user}
        , m_password{password} {
        if (!m_connection)
            throw std::runtime_error("Invalid connection!");
    }

    ~DataBase() {
        m_connection->logout();
    }

    bool connect() {
        assert(m_connection);
        return m_connection->login(m_user, m_password);
    }
private:
    IDataBaseConnection *m_connection;
    std::string m_user;
    std::string m_password;
};



struct MockDataBaseConnection : IDataBaseConnection {
    MOCK_METHOD(
        bool, 
        login, 
        (const std::string& user, const std::string& password), 
        (override)
    );

    MOCK_METHOD(
        bool,
        logout,
        (),
        (override)
    );
};


TEST(DBTest, LoginSuccess) {
    // Arrange
    const std::string usernameRef = "username";
    const std::string passwordRef = "password";
    MockDataBaseConnection mockConnection;
    
    DataBase database(
        &mockConnection,
        usernameRef,
        passwordRef
    );

    // Prepare mocks
    EXPECT_CALL(mockConnection, login(_, _))
        .Times(AtLeast(1))
        .WillOnce(Return(true));

    EXPECT_CALL(mockConnection, logout())
        .Times(AtLeast(1));

    // Act
    bool connectionResult = database.connect();

    // Assert
    ASSERT_TRUE(connectionResult);
}


TEST(DBTest, LoginUsernamePassword) {
    // Arrange
    const std::string usernameRef = "username";
    const std::string passwordRef = "password";
    MockDataBaseConnection mockConnection;
    
    DataBase database(
        &mockConnection,
        usernameRef,
        passwordRef
    );

    // Prepare mocks
    EXPECT_CALL(mockConnection, login(usernameRef, passwordRef))
        .Times(AtLeast(1))
        .WillOnce(Return(true));

    EXPECT_CALL(mockConnection, logout())
        .Times(AtLeast(1));

    // Act
    bool connectionResult = database.connect();

    // Assert
    ASSERT_TRUE(connectionResult);
}



TEST(DBTest, LoginFailure) {
    // Arrange
    const std::string usernameRef = "username";
    const std::string passwordRef = "password";
    MockDataBaseConnection mockConnection;
    
    DataBase database(
        &mockConnection,
        usernameRef,
        passwordRef
    );

    // Prepare mocks
    EXPECT_CALL(mockConnection, login(usernameRef, passwordRef))
        .Times(AtLeast(1))
        .WillOnce(Return(false));

    EXPECT_CALL(mockConnection, logout())
        .Times(AtLeast(1));

    // Act
    bool connectionResult = database.connect();

    // Assert
    ASSERT_FALSE(connectionResult);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}