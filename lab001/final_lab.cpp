#include"compute.cpp"
#include<fstream>

static void final_lab() {
	string str;
	string filename;
	string option;
	do {
		cout << "------�˵�------" << endl;
		cout << "-1 ��������" << endl;
		cout << "-2 �ļ�����" << endl;
		cout << "-3 �˳�" << endl;
		cout << "--------------" << endl;
		cin >> option;
		if (option == "1") {
			cout << "���������ʽ:";
			cin >> str;
			compute(str);
		}
		else if (option == "2") {
			cout << "�������ļ���ַ:";
			cin >> filename;
			ifstream ism(filename, ios::in);
			if (!ism) {
				cout << "�ļ���ʧ��" << endl;
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
			cout << "����ѡ��" << endl;
		}
	} while (true);
}
