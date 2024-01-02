#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义患者结构体

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

int main() {
  int choice;

  do {
    // 显示菜单
    printf("\n病房管理系统\n");
    printf("1. 添加患者\n");
	printf("2. 删除患者\n");
    printf("3. 显示患者列表\n");
    printf("4. 查找患者信息\n");
    printf("5. 呼叫护士\n");
    printf("0. 退出\n");
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
		scanf("%d", &newPatient.bedid);
	    
		while (getchar() != '\n'); // 清除输入缓冲区
		
		printf("请输入患者对应的护士: ");
	    fgets(newPatient.correspondingnurse, sizeof(newPatient.correspondingnurse), stdin);
	
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
        printf("1.输入床位号查找\n2.输入患者id查找信息:\n3.退出\n");
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
			  case 3:
				printf("感谢使用！\n");
				break;	
		      default:
		        printf("无效的选择，请重新输入。\n");
		        break;
		    }
	  }else {
	    printf("当前没有患者。\n");
	  }
	  	}while(deletechoice!=3); 
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
			      	printf("请输入要查找的病人的编号\n");
			      	scanf("%d",&byid);
					for(i2=0;i2<patientCount;++i2){
					if(byid==patients[i2].id){
					printf("患者姓名: %s", patients[i2].name);
					printf("年龄: %d\n", patients[i2].age);
					printf("病况: %s\n", patients[i2].condition);
					printf("医护管理人员: %s\n", patients[i2].correspondingnurse);
					printf("-------------------------\n");
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
		  	}while(searchchoice!=3);
	        break;
        
	  case 5:
	    printf("呼叫护士：紧急情况，请护士立即前往病房。\n");
	    break;  
		    
	  case 0:
		printf("感谢使用病房管理系统！\n");
		break;
		
      default:
        printf("无效的选择，请重新输入。\n");
    }
  } while (choice != 0);

  return 0;
}

