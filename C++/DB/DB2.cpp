/*
	class DB 연결
*/

#include <iostream>
#include <mysql/jdbc.h>

using namespace std;
using namespace sql;

#define SERVER_IP	"127.0.0.1:3306"
#define USERNAME	"root"
#define PASSWORD	"12345"
#define DATABASE	"testDB"

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
			cout << "MySQL Connection success!!" << endl;
		}
		catch (SQLException& e) {
			cerr << "MySQL Connection Failed!!" << e.what() << endl;
		}
	}
	void Players() {
		try {
			unique_ptr<Statement> stmt(conn->createStatement());
			unique_ptr<ResultSet> res(stmt->executeQuery("SELECT player_id, username, login_id, login_pw FROM players"));

			while (res->next()) {
				int id = res->getInt("player_id");
				string name = res->getString("username");
				string Login_Id = res->getString("login_id");
				string Login_Pw = res->getString("login_pw");

				cout << "ID: " << id
					<< ", Name: " << name
					<< ", Login ID: " << Login_Id
					<< ", Login PW: " << Login_Pw << endl;
			}
		}
		catch (SQLException& e) {
			cerr << "Query Failed: " << e.what() << endl;
		}
	}
	~MySQLConnector() {
		cout << "MySQL Disconnection!!" << endl;
	}
};

int main()
{
	MySQLConnector db(SERVER_IP, USERNAME, PASSWORD, DATABASE);
	db.Players();
	return 0;
}