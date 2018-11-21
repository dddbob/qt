#include "window.h"

#include <QApplication>
#include <iostream>
#include "globals.h"

using namespace std;

int main(int argc, char *argv[])
{
	try {
		repo = new GIT_REPO(".");
		for (auto b : repo->branches()) {
			cout << b.name() << endl;
		}
		repo->checkout_branch("branch_b");
		repo->branches().create("123");
		repo->branches().erase("123");
		int a = 0;
		for (auto commit : repo->commits()) {
			cout << commit << endl;
			a++;
		}
		string input;
		cout << "please input item that you want to delete" << endl;
		cin >> input;
		for (auto item : repo->config()) {
			cout << item << endl;
			if (item.name() == input) {
				item.erase();
			}
		}
		repo->config().create("123");
		string name, email;
		cout << "please input name and email that you want to change" << endl;
		cin >> name, email;
		repo->config()["user.name"] = name;
		repo->config()["user.email"] = email;
	}
	catch (GIT_EXCEPTION_CANT_FIND const &e) {
		repo = new GIT_REPO(GIT_REPO::create_t::_create, ".");
	}

	QApplication app(argc, argv);
	tab_window = new  TAB_WINDOW();

	tab_window ->show();
	return app.exec();
}
