#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 患者信息 
typedef struct PatientNode{
int id;
wchar_t name[20];
int age;
wchar_t gender[4];
struct PatientNode *next;
}PatientNode;

PatientNode *patientHead = NULL; 

// 床位信息 
typedef struct BedNode{
int id;
char bedType;
char state;
PatientNode *patient;
struct BedNode *next;
}BedNode;

BedNode *bedHead = NULL;

// 医护人员信息 
typedef struct StaffNode{
int id;
char name[20];
struct StaffNode *next;
}StaffNode;

StaffNode *staffHead = NULL;

// 费用信息
typedef struct CostNode{
int id;
float amount;
char payWay;
struct CostNode *next;
}CostNode;

CostNode *costHead = NULL;


// 菜单显示
void menu(){
printf("------------------\n");
printf(" 医院病房管理系统\n\n");
printf("1. 患者信息管理\n");
printf("2. 床位管理\n");
printf("3. 医护人员管理\n");
printf("4. 费用管理\n");
printf("0. 退出\n");
printf("------------------\n");
}

// 患者管理 
void patientManager() {
	
int choice;

while(1) {
printf("------------------\n");
printf("患者管理界面:\n");
printf("1. 增加患者信息\n");
printf("2. 删除患者信息\n");
printf("3. 更新患者信息\n");
printf("4. 搜索患者信息\n"); 
printf("5. 列出所有患者信息\n");
printf("0. 回到主界面\n");
printf("------------------\n");

scanf("%d", &choice);

switch(choice) {
  case 1:; // 患者入院 
    
    PatientNode *newNode;
    newNode = (PatientNode*)malloc(sizeof(PatientNode));
    
    printf("请输入患者id: ");
    scanf("%d", &newNode->id);
    
    printf("请输入患者姓名: "); 
    wscanf(L"%ls", newNode->name);

    printf("请输入患者性别: "); 
    wscanf(L"%ls", newNode->gender);

    printf("请输入患者年龄: "); 
    scanf("%d", &newNode->age);

    // 头插法插入 
    
    newNode->next = patientHead;
    patientHead = newNode;
    break;
    
  case 2:; // 患者出院 
  
    int id2;
    printf("请选择要删除的患者id: ");
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
      printf("患者信息不存在\n");
    }
    else {
      if(prev != NULL) {
        prev->next = current2->next; 
      }
      else {
        patientHead = current2->next;
      }
      free(current2);
      printf("患者信息已被删除\n");
    }
    break;
    
  case 3:;
  
    int id3;
    printf("请选择要更新的患者id：");
    scanf("%d", &id3);
    PatientNode *current3 = patientHead;
    while (current3 != NULL){
      printf("请输入患者姓名: "); 
      wscanf(L"%ls", current3->name);

      printf("请输入患者性别: "); 
      wscanf(L"%ls", current3->gender);

      printf("请输入患者年龄: "); 
      scanf("%d", &current3->age);
	  current3 = current3->next;
	}
    break;
    

  case 4:;
  	int id4;
    printf("请选择要搜素的患者id：");
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
      printf("没有这个选项噢!\n");

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

    //其他case处理
    
    default:
      printf("Invalid choice\n");
  }

  menu();
  scanf("%d", &choice);
  }

  return 0;
  }

  
