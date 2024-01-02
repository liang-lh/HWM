#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


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

typedef struct {
  char name[50];
  int age;
  char condition[100];
  int floor;
  int room;
  int bedid;
  int id;
  char correspondingnurse[100];
}Patient;
#define MAX_PATIENTS 100
Patient patients[MAX_PATIENTS];
int patientCount = 0;

// 医护人员信息 
struct MedicalStaff {
    char name[50];
    int id;
    int managedBeds[20];
};

struct MedicalStaff staffArray[100];
int staffCount = 0;


// 费用信息
typedef struct {
	int id;
	float amount;
	char payWay;
} Cost;

typedef struct CostNode {
	Cost cost;
	struct CostNode *next;
} CostNode;

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
printf("请输入你想使用的功能: ");

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
    
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    char time_string[100];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
    
    FILE* f;
    f = fopen("log.txt", "a+");
    if (f != NULL)
    {
        fprintf(f, "%s 患者id:%d 患者姓名:%ls 患者性别:%ls 患者年龄:%d\n", time_string, newNode->id, newNode->name, newNode->gender, newNode->age);
        fclose(f);
        f=NULL;
    }

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

void costManager() {
	int choice;

	while (1) {
		printf("------------------\n");
		printf("费用管理界面：\n");
		printf("1. 添加费用单\n");
		printf("2. 删除费用单\n");
		printf("3. 更新费用\n");
		printf("4. 查询费用\n");
		printf("5. 列出所有费用单\n");
		printf("0. 返回主菜单\n");
		printf("------------------\n");

		printf("请输入你想使用的功能: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:; // 添加费用
				CostNode *newCostNode = (CostNode *)malloc(sizeof(CostNode));
			
				printf("输入你的id: ");
				scanf("%d", &newCostNode->cost.id);
			
				printf("输入你的费用: ");
				scanf("%f", &newCostNode->cost.amount);
			
				printf("请选择你想使用的支付方法(1为现金, 2为信用卡, 3为其他): ");
				scanf(" %c", &newCostNode->cost.payWay);
				
				time_t current_time = time(NULL);
			    struct tm *local_time = localtime(&current_time);
			    char time_string[100];
			    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

				FILE* f;
			    f = fopen("log.txt", "a+");
			    if (f != NULL)
			    {
			        fprintf(f, "%s 患者id:%d 患者费用:%f 患者支付方法:%c\n", time_string, newCostNode->cost.id, newCostNode->cost.amount, newCostNode->cost.payWay);
			        fclose(f);
			        f=NULL;
			    }
			
			
				// 将新费用节点插入链表头部
				newCostNode->next = costHead;
				costHead = newCostNode;
				printf("添加完成!\n");
				break;

			case 2:; // 删除费用
				int costID;
				printf("请输入你要删除的id: ");
				scanf("%d", &costID);
			
				CostNode *current = costHead;
				CostNode *prev = NULL;
			
				// 遍历链表找到要删除的节点
				while (current != NULL && current->cost.id != costID) {
					prev = current;
					current = current->next;
				}
			
				if (current == NULL) {
					printf("找不到！\n");
					return;
				}
			
				// 将节点从链表中移除
				if (prev == NULL) {
					// 删除的是头节点
					costHead = current->next;
				} else {
					prev->next = current->next;
				}
			
				free(current);
				printf("删除成功\n");
				break;

			case 3:; // 更新费用
				int costID3;
				printf("输入你想更新的id: ");
				scanf("%d", &costID3);
			
				CostNode *current3 = costHead;
			
				// 遍历链表找到要更新的节点
				while (current3 != NULL && current3->cost.id != costID3) {
					current3 = current3->next;
				}
			
				if (current3 == NULL) {
					printf("找不到!\n");
					return;
				}
			
				// 获取新的费用信息
				printf("输入费用: ");
				scanf("%f", &current->cost.amount);
			
				printf("输入一个新的支方式 (1为现金, 2为信用卡, 其他为其他): ");
				scanf(" %c", &current->cost.payWay);
			
				printf("更新完毕\n");
				break;

			case 4:; // 搜索费用
				int costID4;
				printf("输入你想查询的id: ");
				scanf("%d", &costID4);
			
				CostNode *current4 = costHead;
			
				// 遍历链表找到要搜索的节点
				while (current4 != NULL && current4->cost.id != costID4) {
					current4 = current4->next;
				}
			
				if (current4 == NULL) {
					printf("找不到!\n");
					return;
				}
			
				// 打印费用信息
				printf("费用发现！ - ID: %d, 金额: %.2f, 支付方式: %c\n", current4->cost.id, current4->cost.amount,
				       current4->cost.payWay);
				break;

			case 5:; // 列出所有费用
				CostNode *current5 = costHead;
				printf("\n所有费用信息都在这\n");
				while (current5 != NULL) {
					printf("ID: %d, 金额: %.2f, 支付方式: %c\n", current5->cost.id, current5->cost.amount, current5->cost.payWay);
					current5 = current5->next;
				}
				break;

			case 0:
				return; // 返回上一层菜单

			default:
				printf("没有这个选项噢!\n");
		}
	}
}

void bedManager() {
	  int choice;

  do {
    // 显示菜单
    printf("------------------\n");
    printf("病房管理界面：\n");
    printf("1. 添加患者\n");
	printf("2. 删除患者\n");
    printf("3. 显示患者列表\n");
    printf("4. 查找患者信息\n");
    printf("5. 呼叫护士\n");
    printf("0. 退出\n");
    printf("------------------\n");
    printf("请选择操作：");
    scanf("%d", &choice);

    // 根据用户选择执行相应操作
    switch (choice) {
      case 1:
      if (patientCount < MAX_PATIENTS) {
	    Patient newPatient;
	
	    // 输入患者信息
	    while (getchar() != '\n'); // 清除输入缓冲区
	    
	    printf("请输入患者的ID: ");
	    scanf("%d", &newPatient.id);
	    
	    printf("请输入患者姓名: ");
	    scanf("%s", &newPatient.name);
	    
	    printf("请输入患者年龄: ");
	    scanf("%d", &newPatient.age);
	    while (getchar() != '\n'); // 清除输入缓冲区
	
	    printf("请输入患者病况: ");
	    fgets(newPatient.condition, sizeof(newPatient.condition), stdin);
	
	    printf("请输入患者所在楼层: ");
	    scanf("%d", &newPatient.floor);
	
	    printf("请输入患者所在房间: ");
	    scanf("%d", &newPatient.room);
	    
		printf("请输入患者的床位号: ");
		scanf("%d", &newPatient.bedid);time_t current_time = time(NULL);
		
	    struct tm *local_time = localtime(&current_time);
	    char time_string[100];
	    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
	    
		while (getchar() != '\n'); // 清除输入缓冲区
		
		printf("请输入患者对应的护士: ");
	    fgets(newPatient.correspondingnurse, sizeof(newPatient.correspondingnurse), stdin);
	    
	    
		FILE* f;
	    f = fopen("log.txt", "a+");
	    if (f != NULL)
	    {
	        fprintf(f, "%s 患者id:%d 患者姓名:%s 患者年龄:%d 患者病况:%s 患者所在楼层:%d 患者所在房间:%d 患者的床位号:%d 患者对应的护士:%s\n", time_string, newPatient.id, newPatient.name, newPatient.age, newPatient.condition, newPatient.floor, newPatient.room, newPatient.bedid, newPatient.correspondingnurse);
	        fclose(f);
	        f=NULL;
	    }
	
	    // 将新患者添加到数组
	    patients[patientCount++] = newPatient;
	
	    printf("患者信息已添加。\n");
	  } else {
	    printf("病房已满，无法添加新患者。\n");
	  }
        break;
      case 2:;
	int deletechoice,deletebyid,deletebybedid;

	do{
        printf("1.输入床位号查找\n2.输入患者id查找信息:\n0.退出\n");
	    scanf("%d", &deletechoice);
	if (patientCount > 0) {
	    
	    switch (deletechoice) {
		      case 1:;
		      	int i;
		      	printf("请输入床位号\n");
		      	scanf("%d",&deletebybedid);
		       for(i=0;i<patientCount;++i){
			   	if(deletebybedid==patients[i].bedid){
				patients[i].age=patients[i+1].age;
				patients[i].floor=patients[i+1].floor;
				patients[i].room=patients[i+1].room;
				patients[i].id=patients[i+1].id;
				patients[i].bedid=patients[i+1].bedid;
				*patients[i].condition=*patients[i+1].condition;
				*patients[i].name=*patients[i+1].name;
				*patients[i].correspondingnurse=*patients[i+1].correspondingnurse;
				patientCount=patientCount-1;
				printf("已成功删除\n-------------------------\n");
			   }else{if(i==patientCount)
			   	printf("现在没有病人\n");
			   }}
		        break;
		        
		      case 2:;
		        int i2;
		      	printf("请输入要查找的病人的编号\n");
		      	scanf("%d",&deletebyid);
				for(i2=0;i2<patientCount;++i2){
				if(deletebyid==patients[i2].id){
				patients[i2].age=patients[i2+1].age;
				patients[i2].floor=patients[i2+1].floor;
				patients[i2].room=patients[i2+1].room;
				patients[i2].id=patients[i2+1].id;
				patients[i2].bedid=patients[i2+1].bedid;
				*patients[i2].condition=*patients[i2+1].condition;
				*patients[i2].name=*patients[i2+1].name;
				*patients[i2].correspondingnurse=*patients[i2+1].correspondingnurse;
				patientCount=patientCount-1;
				printf("已成功删除\n-------------------------\n");
				}else{
				printf("该病人编号不存在\n");
				}
				break;}
			  case 0:
				printf("感谢使用！\n");
				break;	
		      default:
		        printf("无效的选择，请重新输入。\n");
		        break;
		    }
	  }else {
	    printf("当前没有患者。\n");
	  }
	  	}while(deletechoice!=0); 
		break;
		
		
      case 3:;
      	int i3;
          if (patientCount > 0) {
		    printf("\n患者列表\n");
		    for (i3 = 0; i3 < patientCount; ++i3) {
		      printf("ID: %d\n", patients[i3].id);
		      printf("患者姓名: %s\n", patients[i3].name);
		      printf("年龄: %d\n", patients[i3].age);
		      printf("病况: %s", patients[i3].condition);
		      printf("楼层: %d\n", patients[i3].floor);
		      printf("房间: %d\n", patients[i3].room);
		      printf("床位号: %d\n", patients[i3].bedid);
		      printf("医护管理人员: %s\n", patients[i3].correspondingnurse);
		      printf("-------------------------\n");
		    }
		  } else {
		    printf("当前没有患者。\n");
		  };
        break;
        
      case 4:;
      	int searchchoice,byid,bybedid;
		do{
	        printf("1.输入床位号查找\n2.输入患者id查找信息:\n0.退出\n");
		    scanf("%d", &searchchoice);
		if (patientCount > 0) {
		    
		    switch (searchchoice) {
			      case 1:;
			        int i; 
			      	printf("请输入床位号\n");
			      	scanf("%d",&bybedid);
			       for(i=0;i<patientCount;++i){
				   	if(bybedid==patients[i].bedid){
				   	printf("患者姓名: %s", patients[i].name);
					printf("年龄: %d\n", patients[i].age);
			        printf("病况: %s\n", patients[i].condition);
			        printf("医护管理人员: %s\n", patients[i].correspondingnurse);
					printf("-------------------------\n");
				   }else{if(i==patientCount)
				   	printf("现在没有病人\n");
				   }}
			        break;
			      case 2:;
			      	int i2;
			      	printf("请输入要查找的病人的ID：\n");
			      	scanf("%d",&byid);
					for(i2=0;i2<patientCount;++i2){
					if(byid==patients[i2].id){
					printf("患者姓名: %s", patients[i2].name);
					printf("年龄: %d\n", patients[i2].age);
					printf("病况: %s\n", patients[i2].condition);
					printf("医护管理人员: %s\n", patients[i2].correspondingnurse);
					printf("-------------------------\n");
					}else{
					printf("该病人ID不存在\n");
					}
					break;}
				  case 0:
					printf("感谢使用！\n");
					break;	
			      default:
			        printf("无效的选择，请重新输入。\n");
			        break;
			    }
		  }else {
		    printf("当前没有患者。\n");
		  }
		  	}while(searchchoice!=0);
	        break;
        
	  case 5:
	    printf("呼叫护士：紧急情况，请护士立即前往病房。\n");
	    break;  
		    
	  case 0:
		break;
		
      default:
        printf("无效的选择，请重新输入。\n");
    }
  } while (choice != 0);

	
}

void staffManager(){
    int choice;

    do {
        // 显示菜单
        printf("\n医护人员管理系统\n");
        printf("1. 录入医护人员信息\n");
        printf("2. 查询医护人员信息\n");
        printf("3. 修改医护人员信息\n");
        printf("4. 删除医护人员信息\n");
        printf("0. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        // 根据用户选择执行相应功能
        switch (choice) {
        case 1:; 
            struct MedicalStaff newStaff;

		    // 输入医护人员信息
		    printf("\n请输入医护人员信息:\n");
		    printf("姓名: ");
		    scanf("%s", newStaff.name);
		    printf("ID: ");
		    scanf("%d", &newStaff.id);
		
		    // 录入病床信息
		    printf("请输入ID为%d的医护人员管理的床位信息（0表示未管理，1表示管理）:\n", newStaff.id);
		    int i; 
		    for (i = 0; i < 20; i++) {
		        printf("床位%d: ", i + 1);
		        scanf("%d", &newStaff.managedBeds[i]);
		    }
		    
		    time_t current_time = time(NULL);
		    struct tm *local_time = localtime(&current_time);
		    char time_string[100];
		    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
	    
		    FILE* f;
		    f = fopen("log.txt", "a+");
		    if (f != NULL)
		    {
		        fprintf(f, "%s 姓名:%s ID:%d ", time_string, newStaff.name, newStaff.id);
		        fprintf(f, "医护人员管理的床位信息（0表示未管理，1表示管理）:");
		        int h;
		        for (h = 0; h < 20; h++){
		        	fprintf(f, "%d", newStaff.managedBeds[h]);
				}   
				fprintf(f, "\n");
		        fclose(f);
		        f=NULL;
		    }
		
		    // 将新的医护人员添加到数组中
		    staffArray[staffCount++] = newStaff;
		
		    printf("医护人员添加成功！\n");;
            break;
        case 2:
                if (staffCount == 0) {
		        printf("暂无医护人员信息。\n");
		        return;
		    }
		
		    // 遍历数组并显示医护人员信息
		    printf("\n医护人员信息:\n");
		    int i2;
		    for (i2 = 0; i2 < staffCount; i2++) {
		        printf("姓名: %s\n", staffArray[i2].name);
		        printf("ID: %d\n", staffArray[i2].id);
		        printf("管理的床位: ");
		        int j;
		        for (j = 0; j < 20; j++) {
		            printf("%d ", staffArray[i2].managedBeds[j]);
		        }
		        printf("\n\n");
		    }
            break;
        case 3:;
            int targetId;

		    if (staffCount == 0) {
		        printf("暂无医护人员信息。\n");
		        return;
		    }
		
		    // 输入要更新的医护人员的ID
		    printf("\n请输入要更新的医护人员的ID: ");
		    scanf("%d", &targetId);
		
		    // 在数组中查找医护人员
		    int index = -1;
		    int i3;
		    for (i3 = 0; i3 < staffCount; i3++) {
		        if (staffArray[i3].id == targetId) {
		            index = i3;
		            break;
		        }
		    }
		
		    // 如果找到医护人员，则更新信息
		    if (index != -1) {
		        printf("请输入新的姓名: ");
		        scanf("%s", staffArray[index].name);
		
		        // 录入新的病床信息
		        printf("请输入ID为%d的医护人员管理的床位信息（0表示未管理，1表示管理）:\n", targetId);
		        int i3;
		        for (i3 = 0; i3 < 20; i3++) {
		            printf("床位%d: ", i3 + 1);
		            scanf("%d", &staffArray[index].managedBeds[i]);
		        }
		
		        printf("医护人员信息更新成功！\n");
		    }
		    else {
		        printf("未找到ID为%d的医护人员。\n", targetId);
		    }
            break;
        case 4:;
            int targetId4;
		
		    if (staffCount == 0) {
		        printf("暂无医护人员信息。\n");
		        return;
		    }
		
		    // 输入要删除的医护人员的ID
		    printf("\n请输入要删除的医护人员的ID: ");
		    scanf("%d", &targetId4);
		
		    // 在数组中查找医护人员
		    int index4 = -1;
		    int i4;
		    for (i4 = 0; i4 < staffCount; i4++) {
		        if (staffArray[i4].id == targetId4) {
		            index4 = i4;
		            break;
		        }
		    }
		
		    // 如果找到医护人员，则删除信息
		    if (index4 != -1) {
		        // 将后面的元素向前移动，覆盖要删除的元素
		        int i;
		        for (i = index4; i < staffCount - 1; i++) {
		            staffArray[i] = staffArray[i + 1];
		        }
		        staffCount--;
		        printf("ID为%d的医护人员信息删除成功！\n", targetId4);
		    }
		    else {
		        printf("未找到ID为%d的医护人员。\n", targetId4);
		    }
            break;
        case 0:
            printf("正在退出程序。再见！\n");
            break;
        default:
            printf("无效的选择，请重试。\n");
        }
    } while (choice != 0);
    return;
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
    
      case 2:
         bedManager();
         break;
       
      case 3:
         staffManager();
         break;

      case 4:
         costManager();
         break;

    //其他case处理
    
    default:
      printf("没有这个选项噢!\n");
  }

  menu();
  scanf("%d", &choice);
  }

  return 0;
  }

  
