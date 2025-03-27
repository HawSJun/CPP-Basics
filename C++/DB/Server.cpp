#include <windows.h>
#include <iostream>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

#define SERVER_IP "127.0.0.1:3306"
#define USERNAME "root"
#define PASSWORD "12345"
#define DATABASE "Pokemon"

class Player {
private:
    int id;
    string name;
    string login_id;
    string login_pw;

public:
    // 생성자
    Player(int _id, const string& _name, const string& _login_id, const string& _login_pw)
        : id(_id), name(_name), login_id(_login_id), login_pw(_login_pw) {
    }

    // Getter 함수
    int getId() const { return id; }
    string getName() const { return name; }
    string getLoginId() const { return login_id; }
    string getLoginPw() const { return login_pw; }

    // Setter 함수
    void setName(const string& newName) { name = newName; }
    void setLoginId(const string& newId) { login_id = newId; }
    void setLoginPw(const string& newPw) { login_pw = newPw; }
};

class MySQLConnector {
private:
    string server;
    string username;
    string password;
    string database;
    unique_ptr<Connection> conn;
public:
    MySQLConnector(const string& serv, const string& user, const string& pw, const string& db)
        : server(serv), username(user), password(pw), database(db) {
        try {

            mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
            conn = unique_ptr<Connection>(driver->connect(server, username, password));

            conn->setSchema(database);


            cout << "MySQL Connection success\n" << endl;
        }
        catch (SQLException& e) {
            cout << "MySQL Connection failed\n" << e.what() << endl;
        }
    }
    ~MySQLConnector() {
        cout << "MySQL Disconnect\n" << endl;
    }

    vector<Player> getAllPlayers() {            // 모든 플레이어 정보를 가져오는 함수
        vector<Player> players;                 // 플레이어 리스트 저장
        try {
            unique_ptr<Statement> stmt(conn->createStatement());                        // SQL 명령어 실행을 위한 Statement 객체 생성
            unique_ptr<ResultSet> res(stmt->executeQuery("SELECT * FROM player"));      // SELECT 쿼리 실행, 결과는 ResultSet 객체로 받음

            while (res->next()) {                               // 결과 한줄 씩 읽음
                int id = res->getInt("id");
                string name = res->getString("name");
                string login_id = res->getString("login_id");
                string login_pw = res->getString("login_pw");

                Player player(id, name, login_id, login_pw);
                players.push_back(player);                          // Player 객체 생성 후 벡터에 추가
            }
        }
        catch (SQLException& e) {
            cout << "Query failed: " << e.what() << endl;
        }
        return players;
    }

};



int main() {
    SetConsoleOutputCP(CP_UTF8);
    MySQLConnector db(SERVER_IP, USERNAME, PASSWORD, DATABASE);
    vector<Player> players = db.getAllPlayers();                    // 모든 플레이어 정보를 데이터베이스에서 가져옴

    for (vector<Player>::const_iterator i = players.begin(); i != players.end(); ++i) {     // 가져온 플에이어 정보를 콘솔에 출력
        const Player& p = *i;

        cout << "ID: " << p.getId()
            << ", Name: " << p.getName()
            << ", Login ID: " << p.getLoginId()
            << ", Login PW: " << p.getLoginPw() << endl;
    }


    return 0;
}

// players.begin() : 벡터의 처음 위치
// i != players.end() : 벡터의 끝이 아닐 때까지 반복