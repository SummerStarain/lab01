#include"final_lab.cpp"

int main() {
	string str;
	char option;
	 do{
		 cout << "请输入算数表达式:";
		 cin >> str;
		 final_lab(str);
		 cout << "是否继续计算(y/n):";
		 cin >> option;
		 if (option == 'n') {
			 break;
		 }
	 } while (true);
	system("pause");
	return 0;
}
