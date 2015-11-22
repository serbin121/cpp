#include <iostream>
#include <cstring>
using namespace std;
class String
{
	unsigned size = 0;
	char* str = nullptr;
public:
	String(const char* s){
		if (s && *s) {
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}
	~String() {
		if (str) {
			delete[] str;
			str = nullptr;
		}
	}
	void assign(const char* s) {
		if (s && *s) {
			size = strlen(s) + 1;
			delete[] str;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}
	void concat(const char* s) {
		if (s && *s && str && *str) {
			size += strlen(s);
			char* new_str = new char[size];
			strcpy_s(new_str, (strlen(str) + 1), str);
			strcat_s(new_str, size, s);
			delete[] str;
			str = new_str;
		}
	}
	void replacement(const char* simb, int position) {
		for (int i = 0; i < size; ++i) {
			if (position == i)
				str[i] = *simb;
		}
	}
	void insert(const char* simb, int position) {
		size += 1;
		char *new_str = new char[size];
		if (position <= size){
			strcpy_s(new_str, size, str);
			new_str[position - 1] = *simb;
			for (int i = position; i < size; ++i)
				new_str[i] = str[i - 1];
		}
		if (position > size){
			strcpy_s(new_str, (strlen(str) + 1), str);
			strcat_s(new_str, size, simb);
		}
		delete[] str;
		str = new_str;
	}
	void ASC2() {
		for (int i = 0; i < strlen(str); ++i) {
			int asc2 = str[i];
			cout << asc2 << " ";
		}
		cout << endl;
	}
	char* caps_lock(){
		return _strupr(str);
	}
	char* NOT_caps_lock(){
		return _strlwr(str);
	}
	const int size_str(){
		return strlen(str);
	}
	const char* get_str() {
		return str;
	}
};
int main() {
	String st("ds");
	cout << st.get_str() << endl;
	st.assign("mornefo");
	cout << st.get_str() << endl;
	st.concat("hfkdsdjk");
	cout << st.get_str() << endl;
	st.insert("*", 18);
	cout << st.get_str() << endl;
	st.ASC2();
	cout << st.caps_lock() << endl;
	cout << st.NOT_caps_lock() << endl;
	cout << st.size_str() << endl;
	return 0;
}
