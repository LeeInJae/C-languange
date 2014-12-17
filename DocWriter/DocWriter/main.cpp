#include "DocWriter.h"
#include "HTMLWriter.h"

int main(void){
	DocWriter * docW1 = new DocWriter("test.txt", "good programmer yeah!");
	docW1->Write();

	HTMLWriter * htmlW1 = new HTMLWriter();
	htmlW1->SetFileNaMe("test.html");
	htmlW1->SetContent("I muse be a good programmer~!");
	htmlW1->SetFont("Arial", 16, "blue");
	htmlW1->Write();
	delete docW1;
	delete htmlW1;
	getchar();
	return 0;
}