// to know more: http://clubes.obmep.org.br/blog/a-matematica-nos-documentos-a-matematica-dos-cpfs/#:~:text=Os%20primeiros%20oito%20dígitos%2C%20ABCDEFGH,dos%20noves%20anteriores%20a%20ele.

#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "portuguese");

	string CPF;
	int qntDig{ 0 };
	int qntDigNum{ 0 };
	bool val{ false };

	std::cout << "CPF: ";
	cin >> CPF;

	// check if the string have 11 digits
	for (int c : CPF) {
		if (isalnum(c)) {
			qntDig++;
		}
	}
	
	// check if the 11 digits are numbers
	if (qntDig == 11) {
		for (int c : CPF) {
			if (isdigit(c)) {
				qntDigNum++;
			}
		}
	}
	if (qntDigNum != 11 || qntDig != 11){
		std::cout << "\n\nCPF Inválido. Houve algo de errado com a escrita.\n";
		return 0;
	}
	//cut the CPF in your firsts nine digits;
	string NumCPF{ (CPF.substr(0, 9)) };

	//calculate verify digits
	int DV1{ 0 };
	int j{ 10 };
	for (int c{ 0 }; c <= 8; c++) {
		DV1 += (NumCPF[c] - '0') * j;
		j--;
	}
	DV1 = 11 - (DV1 % 11);
	if (DV1 == 1) { }

	int DV2{ 0 };

	NumCPF += to_string(DV1);
	j = 11;
	for (int c{ 0 }; c <= 9; c++) {
		DV2 += (NumCPF[c] - '0') * j;
		j--;
	}
	DV2 = 11 - (DV2 % 11);
	NumCPF += to_string(DV2);
	//conclusion
	if (CPF == NumCPF) {
		std::cout << "\nCPF válido.\n";
	}
	else {
		std::cout << "\nCPF inválido\n";
	}
	//Show fiscal region
	std::cout << "Região fiscal de emissão do CPF: ";
		switch (CPF[8]) {
		case '1': std::cout << "DF, GO, MS, MT ou TO";
			break;
		case '2': std::cout << "AC, AM, AP, PA, RO ou RR";
			break;
		case '3': std::cout << "CE, MA ou PI";
			break;
		case '4': std::cout << "AL, PB, PE, RN";
			break;
		case '5': std::cout << "BA ou SE";
			break;
		case '6': std::cout << "MG";
			break;
		case '7': std::cout << "ES ou RJ";
			break;
		case '8': std::cout << "SP";
			break;
		case '9': std::cout << "PR ou SC";
			break;
		case '0': std::cout << "RS";
			break;

		default: std::cout << "ERROR";
		}
	return 0;
}