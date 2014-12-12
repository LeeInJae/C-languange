#include <iostream>

using namespace std;

typedef void(*SYSTEMFUNC)();

void ForWindows9x();
void ForWindowsNT();
bool IsWindows9x();

void ImportantFunc(void(*func)());
void ImportantFunc2(SYSTEMFUNC pSystemFunc);
void ForWindows9x(){
	cout << "Windows 9x함수용 호출됨" << endl;
}


void ForWindowsNT(){
	cout << "Windows NT함수용 호출됨" << endl;
}
bool IsWindows9x(){
	return false;
}

void ImportantFunc(void(*pSystemFunc)()){
	(*pSystemFunc)();
	(*pSystemFunc)();
}

void ImportantFunc2(SYSTEMFUNC pSystemFunc)
{
	(*pSystemFunc)();
	(*pSystemFunc)();
}

int main(void){
	SYSTEMFUNC pfn;
	if (IsWindows9x())
		pfn = &ForWindows9x;
	else
		pfn = &ForWindowsNT;

	ImportantFunc(pfn);
	ImportantFunc2(pfn);
	getchar();
	return 0;
}