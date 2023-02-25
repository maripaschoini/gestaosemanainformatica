#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

// structs
// struct de cadastro de palestrante
struct Spalestrante
{
	string nome;
	string formacao;
	string celular;
	string email;
	string nomedaempresa;
	string curriculo;
};
// sctruct do aluno
struct Saluno
{
	string cpf;
	string nome;
	string curso;
	string periodo;
	string celular;
	string email;
};
// struct de evento
struct Sevento
{
	string nome;
	string tipo;
	string data;
	string hora;
	string local;
	string palestrante;
	int numerovagas;

};
// struct de inscri��o no evento
struct Sinscricao
{
	string cpf;
	string evento;
	string datainscricao;
};

// FUN��ES
void Menu();
void Falterapalestrante (string& busca_palestrante, string& novo_palestrante);
void Falteraaluno (string& busca_aluno, string& novo_aluno);
void Falteraevento (string& busca_evento, string& novo_evento);
int Converte(string s);
//main
int main ()
{
	setlocale(LC_ALL, "portuguese");

	// vari�veis
	Spalestrante palestrante;
	Saluno aluno;
	Sevento evento;
	Sinscricao inscricao;
	int op, total_eventos, total_palestrante, cont, linhaslidas, vartemp;
	char opc;
	string busca, novo, conteudo_novo, linha, maxvagas;
	//arquivos
	fstream arquivopalestrante;
	fstream arquivoaluno;
	fstream arquivoevento;
	fstream arquivoinscricao;


	while(op != 5)
	{
		Menu();
		cin >> op;
		system("CLS");
		switch(op)
		{
		case 1:   // cadastro de palestrante
			cout << "-------------------------------\n";
			cout << "|            OP��ES           |\n";
			cout << "-------------------------------\n";
			cout << "|[1] Mostrar palestrantes     |\n";
			cout << "|[2] Inser��o de palestrante  |\n";
			cout << "|[3] Altera��o de palestrante |\n";
			cout << "|[4] Sair                     |\n";
			cout << "-------------------------------\n";
			cout << "Escolha uma op��o do menu acima. ";
			cin >> op;
			switch (op)
			{
			case 1: // mostrar palestrantes
				system("CLS");
				arquivopalestrante.open("arquivopalestrante.txt", ios::in);
				cout << "PALESTRANTES: \n\n";
				if (arquivopalestrante.is_open())
				{
					while(getline(arquivopalestrante, linha))
					{
						cout << linha << endl;

					}
					arquivopalestrante.close();
				}
				else
				{
					cout << "N�o foi poss�vel abrir o arquivo. ";
				}

				break;

			case 2: //inser��o de palestrante
				system("CLS");
				opc = 's';
				while((opc == 's') or (opc == 'S'))
				{
					arquivopalestrante.open("arquivopalestrante.txt", ios::out | ios::app);
					cout << "-------------------------------\n";
					cout << "    Inser��o de Palestrante: \n";
					cout << "-------------------------------\n\n";
					cout << "Nome: ";
					cin.ignore();
					getline(cin, palestrante.nome) ;
					arquivopalestrante << palestrante.nome << endl;
					cout << "Forma��o: ";
					getline(cin, palestrante.formacao);
					arquivopalestrante << palestrante.formacao << endl;
					cout << "Celular: ";
					cin >> palestrante.celular;
					arquivopalestrante << palestrante.celular << endl;
					cout << "Email: ";
					cin >> palestrante.email;
					arquivopalestrante << palestrante.email << endl;
					cout << "Nome da empresa: ";
					cin.ignore();
					getline(cin, palestrante.nomedaempresa);
					arquivopalestrante << palestrante.nomedaempresa << endl;
					cout << "Curr�culo: ";
					getline(cin, palestrante.curriculo);
					arquivopalestrante << palestrante.curriculo << endl;
					arquivopalestrante.close();
					total_palestrante++;
					cout << "\n \n ";
					cout << "Palestrante cadastrado. \n Deseja cadastrar outro? [s]/[n]";
					cin >> opc;
				}

				break;
			case 3:   // alterar palestrante
				system("CLS");
				cout << "-------------------------------\n";
				cout << "     Altera��o de Palestrante: \n";
				cout << "-------------------------------\n\n";
				cout << "Campos dispon�veis para altera��o:\n";
				cout << " [1]Nome \n [2]Forma��o \n [3]Celular \n [4]Email \n [5]Nome da empresa \n [6]Curr�culo \n";
				cout << "-------------------------------\n";
				getline(arquivoevento, linha);
				cin >> op;
				switch(op)
				{
				case 1:
					system("CLS");
					cout << "Nome atual: ";
					cin >> busca;
					cout << "Novo nome: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 2:
					system("CLS");
					cout << "Forma��o atual: ";
					cin >> busca;
					cout << "Nova forma��o: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 3:
					system("CLS");
					cout << "Celular atual: ";
					cin >> busca;
					cout << "Novo celular: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
					getline(arquivoevento, linha);
				case 4:
					system("CLS");
					cout << "Email atual: ";
					cin >> busca;
					cout << "Novo email: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 5:
					system("CLS");
					cout << "Nome da empresa atual: ";
					cin >> busca;
					cout << "Novo nome da empresa: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 6:
					system("CLS");
					cout << "Curr�culo atual: ";
					cin >> busca;
					cout << "Novo curr�culo: ";
					cin >> novo;
					Falterapalestrante(busca, novo);
					cout << "Campo alterado! \n";
					break;
					getline(arquivoevento, linha);
				default:
					system("CLS");
					cout << "Op��o n�o dispon�vel. ";
					break;
				}
				break;
			}
			break;



		case 2:	// cadastro de aluno
			system("CLS");
			cout << "-------------------------------\n";
			cout << "|            OP��ES           |\n";
			cout << "-------------------------------\n";
			cout << "|[1] Mostrar alunos           |\n";
			cout << "|[2] Inser��o de aluno        |\n";
			cout << "|[3] Altera��o de aluno       |\n";
			cout << "|[4] Sair                     |\n";
			cout << "-------------------------------\n";
			cout << "Escolha uma op��o do menu acima. ";
			cin >> op;
			switch (op)
			{
			case 1: // mostrar alunos
				system("CLS");
				arquivoaluno.open("arquivoaluno.txt", ios::in);
				cout << "ALUNOS: \n\n";
				if (arquivoaluno.is_open())
				{
					while(getline(arquivoaluno, linha))
					{
						cout << linha << endl;

					}
					arquivoaluno.close();
				}
				else
				{
					cout << "N�o foi poss�vel abrir o arquivo. ";
				}

				break;
			case 2: // inser��o de aluno
				system("CLS");
				opc = 's';
				while((opc == 's') or (opc == 'S'))
				{
					arquivoaluno.open("arquivoaluno.txt", ios::out | ios::app);
					cout << "-------------------------------\n";
					cout << "    Inser��o de Aluno: \n";
					cout << "-------------------------------\n\n";
					cout << "Nome: ";
					cin.ignore();
					getline(cin, aluno.nome);
					arquivoaluno << aluno.nome <<  endl;
					cout << "CPF: ";
					getline(cin, aluno.cpf);
					arquivoaluno << aluno.cpf <<  endl;
					cout << "Curso: ";
					getline(cin, aluno.curso);
					arquivoaluno << aluno.curso << endl;
					cout << "Per�odo: ";
					cin >> aluno.periodo;
					arquivoaluno << aluno.periodo << endl;
					cout << "Email: ";
					cin.ignore();
					getline(cin, aluno.email);
					arquivoaluno << aluno.email << endl;
					cout << "Celular: ";
					cin >> aluno.celular;
					arquivoaluno << aluno.celular << endl;
					arquivoaluno.close();
					cout << "\n \n ";
					cout << "Aluno cadastrado. \nDeseja cadastrar outro? [s]/[n]";
					cin >> opc;
				}
				break;
			case 3: // alterar aluno
				system("CLS");
				cout << "-------------------------------\n";
				cout << "     Altera��o de Aluno: \n";
				cout << "-------------------------------\n\n";
				cout << "Campos dispon�veis para altera��o:\n";
				cout << " [1]CPF \n [2]Nome \n [3]Curso \n [4]Per�odo \n [5]Celular \n [6]Email \n";
				cout << "-------------------------------\n";
				cin >> op;
				switch(op)
				{
				case 1:
					system("CLS");
					cout << "CPF atual: ";
					cin >> busca;
					cout << "Novo CPF: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 2:
					system("CLS");
					cout << "Nome atual: ";
					cin >> busca;
					cout << "Novo nome: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 3:
					system("CLS");
					cout << "Curso atual: ";
					cin >> busca;
					cout << "Novo curso: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 4:
					system("CLS");
					cout << "Per�odo atual: ";
					cin >> busca;
					cout << "Novo per�odo: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 5:
					system("CLS");
					cout << "Ceular atual: ";
					cin >> busca;
					cout << "Novo celular: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 6:
					system("CLS");
					cout << "Email atual: ";
					cin >> busca;
					cout << "Novo email: ";
					cin >> novo;
					Falteraaluno(busca, novo);
					cout << "Campo alterado! \n";
					break;
				default:
					system("CLS");
					cout << "Op��o n�o dispon�vel. ";
					break;
				}
				break;
				break;
				break;
			case 4:
				break;
			default:
				system("CLS");
				cout << "Op��o inv�lida. ";
				break;
			}
			break;
		case 3: 	// cadastro de eventos

			cout << "-------------------------------\n";
			cout << "|            OP��ES           |\n";
			cout << "-------------------------------\n";
			cout << "|[1] Mostrar eventos          |\n";
			cout << "|[2] Inser��o de evento       |\n";
			cout << "|[3] Altera��o de evento      |\n";
			cout << "|[4] Sair                     |\n";
			cout << "-------------------------------\n";
			cout << "Escolha uma op��o do menu acima. ";
			cin >> op;
			switch (op)
			{
			case 1: // mostrar evento

				arquivoevento.open("arquivoevento.txt", ios::in);
				cout << "EVENTOS: \n\n";
				if(arquivoevento.is_open())
				{
					if (arquivoevento.tellg() == -1)
					{
						cout << "N�o h� eventos no momento.";

					}
					else
					{
						while(getline(arquivoevento, linha))
						{
							cout << linha << endl;

						}
					}
					arquivoevento.close();
				}
				else
				{
					cout << "N�o foi poss�vel abrir o arquivo. ";
				}
				break;

			case 2: // inser��o de evento
				system("CLS");
				opc = 's';
				while((opc == 's') or (opc == 'S'))
				{
					arquivoevento.open("arquivoevento.txt", ios::out | ios::app);
					cout << "-------------------------------\n";
					cout << "    Inser��o de Evento: \n";
					cout << "-------------------------------\n\n";
					cout << "Nome: ";
					cin.ignore();
					getline(cin, evento.nome);
					arquivoevento << evento.nome << endl;
					cout << "Tipo [palestra ou minicurso]: ";
					cin >> evento.tipo;
					arquivoevento << evento.tipo <<  endl;
					cout << "data: ";
					cin >> evento.data;
					arquivoevento << evento.data << endl;
					cout << "Hor�rio:: ";
					cin >> evento.hora;
					arquivoevento << evento.hora << endl;
					cout << "Local: ";
					cin.ignore();
					getline(cin, evento.local);
					arquivoevento << evento.local <<  endl;
					cout << "Numero de vagas: ";
					cin >> evento.numerovagas;
					arquivoevento << evento.numerovagas << endl;
					cout << "Palestrante: ";
					cin.ignore();
					getline(cin, evento.palestrante);
					arquivoevento << evento.palestrante << endl;
					arquivoevento.close();
					total_eventos++;
					cout << "\n \n ";
					cout << "Evento cadastrado. \nDeseja cadastrar outro? [s]/[n]";
					cin >> opc;
					system("CLS");
				}
				break;
			case 3: // alterar evento
				system("CLS");
				cout << "-------------------------------\n";
				cout << "     Altera��o de Evento:      \n";
				cout << "-------------------------------\n\n";
				cout << "Campos dispon�veis para altera��o:\n";
				cout << " [1]Nome \n [2]Tipo [palestra/minicurso] \n [3]Data \n [4]Hor�rio \n [5]Local \n [6]N�mero de Vagas \n [7]Palestrante \n";
				cout << "-------------------------------\n";
				cin >> op;
				switch(op)
				{
				case 1:
					system("CLS");
					cout << "Nome do evento atual: ";
					cin >> busca;
					cout << "Novo nome do evento: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 2:
					system("CLS");
					cout << "Tipo atual: ";
					cin >> busca;
					cout << "Novo tipo: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 3:
					system("CLS");
					cout << "Data atual: ";
					cin >> busca;
					cout << "Nova data: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 4:
					system("CLS");
					cout << "Hor�rio atual: ";
					cin >> busca;
					cout << "Novo hor�rio: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 5:
					system("CLS");
					cout << "Local atual: ";
					cin >> busca;
					cout << "Novo local: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 6:
					system("CLS");
					cout << "N�mero de vagas atual: ";
					cin >> busca;
					cout << "Novo n�mero de vagas: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				case 7:
					system("CLS");
					cout << "Palestrante atual: ";
					cin >> busca;
					cout << "Novo palestrante: ";
					cin >> novo;
					Falteraevento(busca, novo);
					cout << "Campo alterado! \n";
					break;
				default:
					system("CLS");
					cout << "Op��o n�o dispon�vel. ";
					break;

					break;
				}
			}
			break;

		case 4:  // inscri��o no evento
			system("CLS");
			cout << endl;
			cout << "------------------------------- \n";
			cout << "|          INSCRI��O          | \n";
			cout << "------------------------------- \n";
			cout << "|[1] Mostrar inscri��es       | \n";
			cout << "|[2] Realizar inscri��o       | \n";
			cout << "------------------------------- \n";
			cout << " \n ";
			cin >> op;
			switch(op)
			{
			case 1:
				system("CLS");
				cout << "INSCRI��ES \n";
				cont = 1;
				linhaslidas = 0;
				arquivoinscricao.open("arquivoinscricao.txt", ios::in);
				if (arquivoinscricao.is_open())
				{
					while(getline(arquivoinscricao, linha))
					{
						linhaslidas++;
						cout << linha << " - ";

						if (linhaslidas % 3 == 0)
						{
							cout << endl;
							cont++;
						}
					}
				}
				arquivoinscricao.close();

				break;
			case 2:
				system("CLS");
				cont = 1;
				int p = 0;
				arquivoevento.open("arquivoevento.txt", ios::in);
				linhaslidas = 0;
				cout << "EVENTOS: \n\n";
				if(arquivoevento.is_open())
				{

					while(getline(arquivoevento, linha))
					{
						linhaslidas++;
						cout << linha << " - ";

						if (linhaslidas % 7 == 0)
						{
							cout << endl;
							cont++;
						}
					}
				}
				else
				{
					cout << "N�o foi poss�vel abrir o arquivo. ";
				}
				arquivoevento.close();

				arquivoinscricao.open("arquivoinscricao.txt", ios::out | ios::app);

				cout << "\n\nINFORME OS DADOS: \n\n";
				cout << "CPF: ";
				cin >> inscricao.cpf;
				arquivoinscricao << inscricao.cpf << endl;
				cout << "Eventos: ";
				cin.ignore();
				getline(cin, inscricao.evento);
				arquivoinscricao << inscricao.evento << endl;
				cout << "Data da inscri��o: ";
				cin >> inscricao.datainscricao;
				arquivoinscricao << inscricao.datainscricao << endl;
				cout << "INSCRI��O REALIZADA COM SUCESSO! \n";
				arquivoinscricao.close();


				int contaeventos = 0;
				arquivoinscricao.open("arquivoinscricao.txt", ios::in);
				if (arquivoinscricao.is_open())
				{
					while(getline(arquivoinscricao, linha))
					{
						if (linha == inscricao.evento)
							contaeventos++;
					}
				}
				arquivoinscricao.close();

				arquivoevento.open("arquivoevento.txt", ios::in);
				if (arquivoevento.is_open())
				{
					while(getline(arquivoevento, linha))
					{
						linhaslidas++;
						if (linha == inscricao.evento)
						{
							getline(arquivoevento, linha);
							getline(arquivoevento, linha);
							getline(arquivoevento, linha);
							getline(arquivoevento, linha);
							arquivoevento >> vartemp;
						}
					}

				}
				arquivoevento.close();

				if (contaeventos > vartemp)
				{
					cout << "O n�mero de vagas j� foi alcan�ado. Por favor escolha outro evento.\n";
				}

				break;
			}

			break;

		case 5:  // sair
			break;
		default:  // op��o q n�o esteja no menu
			system("CLS");
			cout << "ERRO. OP��O INV�LIDA. ";
			break;


		}
	}

	return 0;
}
// implementa��o das fun��es
void Menu()
{
	cout << "\n";
	cout << "---------------------------------------------\n";
	cout << "|  MENU DE OP��ES - SEMANA DA INFORM�TICA   |\n";
	cout << "---------------------------------------------\n";
	cout << "| [1] Cadastro de palestrantes              |\n";
	cout << "| [2] Cadastro de aluno                     |\n";
	cout << "| [3] Cadastro de eventos                   |\n";
	cout << "| [4] Inscri��o no evento                   |\n";
	cout << "| [5] Sair                                  |\n";
	cout << "---------------------------------------------\n";
	cout << "Escolha uma op��o do menu acima. ";
}
// altera palestrante
void Falterapalestrante (string& busca, string& novo)
{
	fstream arquivopalestrante;
	string linha;
	string conteudo_novo;

	arquivopalestrante.open("arquivopalestrante.txt", ios::in);
	if(arquivopalestrante.is_open())
	{
		while(getline(arquivopalestrante, linha))
		{
			if (linha == busca)
			{
				conteudo_novo += novo + "\n";
			}
			else
			{
				conteudo_novo += linha + "\n";
			}
		}
		arquivopalestrante.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo.";
	}

	arquivopalestrante.open("arquivopalestrante.txt", ios::out);
	if(arquivopalestrante.is_open())
	{
		arquivopalestrante << conteudo_novo;
	}
	arquivopalestrante.close();
}
//altera aluno
void Falteraaluno (string & busca, string & novo)
{
	fstream arquivoaluno;
	string linha;
	string conteudo_novo;

	arquivoaluno.open("arquivoaluno.txt", ios::in);
	if(arquivoaluno.is_open())
	{
		while(getline(arquivoaluno, linha))
		{
			if (linha == busca)
			{
				conteudo_novo += novo + "\n";
			}
			else
			{
				conteudo_novo += linha + "\n";
			}
		}
		arquivoaluno.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo.";
	}

	arquivoaluno.open("arquivoaluno.txt", ios::out);
	if(arquivoaluno.is_open())
	{
		arquivoaluno << conteudo_novo;
	}
	arquivoaluno.close();
}
//altera evento
void Falteraevento (string & busca, string & novo)
{
	fstream arquivoevento;
	string linha;
	string conteudo_novo;

	arquivoevento.open("arquivoevento.txt", ios::in);
	if(arquivoevento.is_open())
	{
		while(getline(arquivoevento, linha))
		{
			if (linha == busca)
			{
				conteudo_novo += novo + "\n";
			}
			else
			{
				conteudo_novo += linha + "\n";
			}
		}
		arquivoevento.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo.";
	}

	arquivoevento.open("arquivoevento.txt", ios::out);
	if(arquivoevento.is_open())
	{
		arquivoevento << conteudo_novo;
	}
	arquivoevento.close();
}


