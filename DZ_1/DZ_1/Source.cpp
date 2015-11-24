#include <iostream>
#include <cstring>
using namespace std;
class String
{
	unsigned size = 0;
	char* str = nullptr;
public:
	String(const char* s) {
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
	void insert(const char simb, unsigned position) {
		if (position <= size) {
			size += 1;
			char *new_str = new char[size];
			strcpy_s(new_str, size, str);
			new_str[position - 1] = simb;
			for (unsigned i = position; i < size; ++i)
				new_str[i] = str[i - 1];
			delete[] str;
			str = new_str;
		}
	}
	void ASC2() {
		for (unsigned i = 0; i < size; ++i) {
			int asc2 = str[i];
			cout << asc2 << " ";
		}
		cout << endl;
	}
	char* caps_lock() {
		_strupr_s(str, size);
		return str;
	}
	char* NOT_caps_lock() {
		_strlwr_s(str, size);
		return str;
	}
	const int size_str() {
		return size;
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
	st.insert('*', 16);
	cout << st.get_str() << endl;
	st.ASC2();
	cout << st.caps_lock() << endl;
	cout << st.NOT_caps_lock() << endl;
	cout << st.size_str() << endl;
	return 0;
}
