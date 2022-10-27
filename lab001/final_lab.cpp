#include"compute.cpp"
#include<fstream>

static void final_lab() {
	string str;
	string filename;
	string option;
	do {
		cout << "------菜单------" << endl;
		cout << "-1 键盘输入" << endl;
		cout << "-2 文件输入" << endl;
		cout << "-3 退出" << endl;
		cout << "--------------" << endl;
		cin >> option;
		if (option == "1") {
			cout << "请输入计算式:";
			cin >> str;
			compute(str);
		}
		else if (option == "2") {
			cout << "请输入文件地址:";
			cin >> filename;
			ifstream ism(filename, ios::in);
			if (!ism) {
				cout << "文件打开失败" << endl;
				continue;
			}
			str = "";
			char ch;
			while (ism.get(ch)) {
				str += ch;
			}

			ism.close();
			compute(str);
		}
		else if (option == "3") {
			break;
		}
		else {
			cout << "错误选择" << endl;
		}
	} while (true);
}
