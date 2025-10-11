#include <HardwareSerial.h>
HardwareSerial SerialEbyte(1);  
#define EBYTE_TX 18
#define EBYTE_RX 19
#define EBYTE_M0 16
#define EBYTE_M1 17

HardwareSerial SerialRS485(2); 
#define RS485_TX 33 //33              
#define RS485_RX 32 //32
#define RS485_RE_DE 25


//variáveis para receber dados do MEGA pela serial
String recebidosAtualizado = "*";  //string onde será armazenado os dados recebidos do MEGA
const uint8_t BUFFER_SIZE = 128;   //número de caracteres que serão recebidos (38) (190) (700)
uint8_t size = 0;
char buffer[BUFFER_SIZE];  //buffer para armazenar bytes recebidos
int controleRecebido = 0;

//strings transformadas em variaveis:
volatile int valorA;
volatile int valorB;
volatile int valorC;
volatile int valorD;
volatile float valorE;
volatile float valorF;
volatile float valorG;
volatile float valorH;
volatile float valorI;
volatile float valorJ;
volatile float valorK;
volatile float valorL;
volatile float valorM;
volatile float valorN;
volatile float valorO;
volatile float valorP;
volatile float valorQ;
volatile float valorR;
volatile float valorS;
volatile float valorT;
volatile float valorU;
volatile float valorV;
volatile float valorW;
volatile float valorX;
volatile float valorY;
volatile float valorZ;
volatile float valorAA;
volatile float valorAB;


String mensagem;  //pacote de dados completo

String valor1;
String valor2;
String valor3;
String valor4;
String valor5;
String valor6;
String valor7;
String valor8;
String valor9;
String valor10;
String valor11;
String valor12;
String valor13;
String valor14;
String valor15;
String valor16;
String valor17;
String valor18;
String valor19;
String valor20;
String valor21;
String valor22;
String valor23;
String valor24;
String valor25;
String valor26;
String valor27;


//long int tempo_ant;

//variaveis para "descompactar" o pacote de dados:
volatile int i = 0;
volatile int separador = 0;
volatile int cont_dado = 1;
volatile int separador_ant = -1;
