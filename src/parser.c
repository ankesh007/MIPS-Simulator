#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "utils.h"

// typedef enum { Monday, Tuesday Thursday} days;
typedef enum {ADD,SUB,AND,MULTIPLY,MULTIPLY_ADD,NOR,OR,LOGIC_SHIFT_LEFT,LOGIC_SHIFT_LEFT_VARIABLE,SUBTRACT,BRANCH_GREATER_OR_EQUAL,BRANCH_GREATER,BRANCH_LESS_OR_EQUAL,BRANCH_LESS,BRANCH_EQUAL,LDR_BYTE,LDR_WORD,STR_BYTE,STR_WORD} instruction_type; 
typedef enum {DP,DT,BRANCH} class_type;
typedef long long int long;

typedef struct 
{
	int rs,rt,rd,shf_amt,opcode,target_address,function,immediate;
	instruction_type Itype;class class_type Ctype;
	
}instruction;


int input()
{
	char *a=malloc(sizeof(char)*10);
	scanf("%s,",`a);

	int num=(int)strtol(a,NULL,16);
	return num; 
}

instruction *instruction_set(int a)
{
	instruction *information=(instruction *)malloc(sizeof(instruction));
	
	int temp=63;
	information->opcode=(a&(temp<<26))>>26;
	temp=(temp>>1);
	information->rs=(a&(temp<<21))>>21;
	information->rt=(a&(temp<<16))>>16;
	information->rd=(a&(temp<<11))>>11;
	information->shf_amt=(a&(temp<<6))>>6;
	information->function=a&((temp<<1)&1);
	information->immediate=rd|shf_amt|funct;
	information->target_address=information->immediate|information->rs|information->rt;

	if(information->opcode==0 && information->function==32 && information->shf_amt==0)
	{
		information->Ctype=DP;
		information->Itype=ADD;
	}
	else if(information->opcode==0 && information->shf_amt==0 && information->function==36)
	{
		information->Ctype=DP;
		information->Itype=AND;
	}
	else if(information->opcode==0 && information->target_address==24)
	{
		information->Ctype=DP;
		information->Itype=MULTIPLY;
	}
	else if(information->opcode==0 && information->target_address==0)
	{
		information->Ctype=DP;
		information->Itype=MULTIPLY_ADD;
	}
	else if(information->opcode==0 && information->shf_amt==0 && information->function==39)
	{
		information->Ctype=DP;
		information->Itype=NOR;
	}
	else if(information->opcode==0 && information->shf_amt==0 && information->function==37)
	{
		information->Ctype=DP;
		information->Itype=OR;
	}
	else if(information->opcode==0 && information->function==0)
	{
		information->Ctype=DP;
		information->Itype=LOGIC_SHIFT_LEFT;
	}
	else if(information->opcode==0 && information->function==4)
	{
		information->Ctype=DP;
		information->Itype=LOGIC_SHIFT_LEFT_VARIABLE;
	}
	else if(information->opcode==0 && information->function==34 && information->shf_amt==0)
	{
		information->Ctype=DP;
		information->Itype=SUBTRACT;
	}
	else if(information->opcode==4)
	{
		information->Ctype=BRANCH;
		information->Itype=BRANCH_EQUAL;
	}
	else if(information->opcode==1 && information->rt==1)
	{
		information->Ctype=BRANCH;
		information->Itype=BRANCH_GREATER_OR_EQUAL;
	}
	else if(information->opcode==7 && information->rt==0)
	{
		information->Ctype=DT;
		information->Itype=BRANCH_GREATER;
	}
	else if(information->opcode==6 && information->rt==0)
	{
		information->Ctype=DT;
		information->Itype=BRANCH_LESS_OR_EQUAL;
	}
	else if(information->opcode==1 && information->rt==0)
	{
		information->Ctype=DT;
		information->Itype=BRANCH_LESS;
	}
	else if(information->opcode==32)
	{
		information->Ctype=DT;
		information->Itype=LDR_BYTE;
	}
	else if(information->opcode==35)
	{
		information->Ctype=DT;
		information->Itype=LDR_WORD;
	}
	else if(information->opcode==40)
	{
		information->Ctype=DT;
		information->Itype=STR_BYTE;
	}
	else if(information->opcode==43)
	{
		information->Ctype=DT;
		information->Itype=STR_WORD;
	}
	else
	{
		throw_error("Wrong Instruction Set.");
	}
}

// int hex_to_int(char *a)
// {
// 	int i=0;
// 	int mul=1;
// 	int res=0;

// 	int x=strlen(a);

// 	for(int i=x-1;i>=0;i--)
// 	{
// 		if(a[i]>='a' && a[i]<='f')
// 		{
// 			res+=(a[i]-'a'+10)*
// 		}
// 	}

// }

void instruction_decode()
{

}

int main(int argc,char *argv[])
{
	printf("%d",input());

}

