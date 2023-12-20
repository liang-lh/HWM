#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// ������Ϣ 
typedef struct PatientNode{
int id;
wchar_t name[20];
int age;
wchar_t gender[4];
struct PatientNode *next;
}PatientNode;

PatientNode *patientHead = NULL; 

// ��λ��Ϣ 
typedef struct BedNode{
int id;
char bedType;
char state;
PatientNode *patient;
struct BedNode *next;
}BedNode;

BedNode *bedHead = NULL;

// ҽ����Ա��Ϣ 
typedef struct StaffNode{
int id;
char name[20];
struct StaffNode *next;
}StaffNode;

StaffNode *staffHead = NULL;

// ������Ϣ
typedef struct CostNode{
int id;
float amount;
char payWay;
struct CostNode *next;
}CostNode;

CostNode *costHead = NULL;


// �˵���ʾ
void menu(){
printf("------------------\n");
printf(" ҽԺ��������ϵͳ\n\n");
printf("1. ������Ϣ����\n");
printf("2. ��λ����\n");
printf("3. ҽ����Ա����\n");
printf("4. ���ù���\n");
printf("0. �˳�\n");
printf("------------------\n");
}

// ���߹��� 
void patientManager() {
	
int choice;

while(1) {
printf("------------------\n");
printf("���߹������:\n");
printf("1. ���ӻ�����Ϣ\n");
printf("2. ɾ��������Ϣ\n");
printf("3. ���»�����Ϣ\n");
printf("4. ����������Ϣ\n"); 
printf("5. �г����л�����Ϣ\n");
printf("0. �ص�������\n");
printf("------------------\n");

scanf("%d", &choice);

switch(choice) {
  case 1:; // ������Ժ 
    
    PatientNode *newNode;
    newNode = (PatientNode*)malloc(sizeof(PatientNode));
    
    printf("�����뻼��id: ");
    scanf("%d", &newNode->id);
    
    printf("�����뻼������: "); 
    wscanf(L"%ls", newNode->name);

    printf("�����뻼���Ա�: "); 
    wscanf(L"%ls", newNode->gender);

    printf("�����뻼������: "); 
    scanf("%d", &newNode->age);

    // ͷ�巨���� 
    
    newNode->next = patientHead;
    patientHead = newNode;
    break;
    
  case 2:; // ���߳�Ժ 
  
    int id2;
    printf("��ѡ��Ҫɾ���Ļ���id: ");
    scanf("%d", &id2);
    
    PatientNode *prev = NULL;
    PatientNode *current2 = patientHead;
    
    while(current2 != NULL) {
      if(current2->id == id2) {
        break;  
      }
      prev = current2;
      current2 = current2->next;
    }
    
    if(current2 == NULL) {
      printf("������Ϣ������\n");
    }
    else {
      if(prev != NULL) {
        prev->next = current2->next; 
      }
      else {
        patientHead = current2->next;
      }
      free(current2);
      printf("������Ϣ�ѱ�ɾ��\n");
    }
    break;
    
  case 3:;
  
    int id3;
    printf("��ѡ��Ҫ���µĻ���id��");
    scanf("%d", &id3);
    PatientNode *current3 = patientHead;
    while (current3 != NULL){
      printf("�����뻼������: "); 
      wscanf(L"%ls", current3->name);

      printf("�����뻼���Ա�: "); 
      wscanf(L"%ls", current3->gender);

      printf("�����뻼������: "); 
      scanf("%d", &current3->age);
	  current3 = current3->next;
	}
    break;
    

  case 4:;
  	int id4;
    printf("��ѡ��Ҫ���صĻ���id��");
    scanf("%d", &id4);
    PatientNode *current4 = patientHead;
    while (current4 != NULL){
      if (current4->id == id4){
        wprintf(L"%d %ls %ls %d\n", current4->id, current4->name, current4->gender, current4->age);
	  }
	  current4 = current4->next;
	}
    break;

    

  case 5:;
    PatientNode *p = patientHead;
    while (p != NULL){
      wprintf(L"%d %ls %ls %d\n", p->id, p->name, p->gender, p->age);
      p = p->next;
    }
    break;
    
  default:
      printf("û�����ѡ����!\n");

  case 0:
    return;

}
}

}


int main(){
  SetConsoleCP(936);  
  SetConsoleOutputCP(936);
  menu();

  int choice;
  scanf("%d", &choice);

  while(choice!=0){	
    switch(choice){

      case 1:
        patientManager();
        break;
    
  //    case 2:
  //       bedManager();
  //       break;
  //     
  //    case 3:
  //       staffManager();
  //       break;
  //    
  //    case 4:
  //       resourceManager();
  //       break;
  //    
  //    case 5:
  //       costManager();
  //       break;

    //����case����
    
    default:
      printf("Invalid choice\n");
  }

  menu();
  scanf("%d", &choice);
  }

  return 0;
  }

  
