#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���廼�߽ṹ��

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
    // ��ʾ�˵�
    printf("\n��������ϵͳ\n");
    printf("1. ��ӻ���\n");
	printf("2. ɾ������\n");
    printf("3. ��ʾ�����б�\n");
    printf("4. ���һ�����Ϣ\n");
    printf("5. ���л�ʿ\n");
    printf("0. �˳�\n");
    printf("��ѡ�������");
    scanf("%d", &choice);

    // �����û�ѡ��ִ����Ӧ����
    switch (choice) {
      case 1:
      if (patientCount < MAX_PATIENTS) {
	    Patient newPatient;
	
	    // ���뻼����Ϣ
	    while (getchar() != '\n'); // ������뻺����
	    
	    printf("�����뻼�ߵ�ID: ");
	    scanf("%d", &newPatient.id);
	    
	    printf("�����뻼������: ");
	    scanf("%s", &newPatient.name);
	    
	    printf("�����뻼������: ");
	    scanf("%d", &newPatient.age);
	    while (getchar() != '\n'); // ������뻺����
	
	    printf("�����뻼�߲���: ");
	    fgets(newPatient.condition, sizeof(newPatient.condition), stdin);
	
	    printf("�����뻼������¥��: ");
	    scanf("%d", &newPatient.floor);
	
	    printf("�����뻼�����ڷ���: ");
	    scanf("%d", &newPatient.room);
	    
		printf("�����뻼�ߵĴ�λ��: ");
		scanf("%d", &newPatient.bedid);
	    
		while (getchar() != '\n'); // ������뻺����
		
		printf("�����뻼�߶�Ӧ�Ļ�ʿ: ");
	    fgets(newPatient.correspondingnurse, sizeof(newPatient.correspondingnurse), stdin);
	
	    // ���»�����ӵ�����
	    patients[patientCount++] = newPatient;
	
	    printf("������Ϣ����ӡ�\n");
	  } else {
	    printf("�����������޷�����»��ߡ�\n");
	  }
        break;
      case 2:;
	int deletechoice,deletebyid,deletebybedid;

	do{
        printf("1.���봲λ�Ų���\n2.���뻼��id������Ϣ:\n3.�˳�\n");
	    scanf("%d", &deletechoice);
	if (patientCount > 0) {
	    
	    switch (deletechoice) {
		      case 1:;
		      	int i;
		      	printf("�����봲λ��\n");
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
				printf("�ѳɹ�ɾ��\n-------------------------\n");
			   }else{if(i==patientCount)
			   	printf("����û�в���\n");
			   }}
		        break;
		        
		      case 2:;
		        int i2;
		      	printf("������Ҫ���ҵĲ��˵ı��\n");
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
				printf("�ѳɹ�ɾ��\n-------------------------\n");
				}else{
				printf("�ò��˱�Ų�����\n");
				}
				break;}
			  case 3:
				printf("��лʹ�ã�\n");
				break;	
		      default:
		        printf("��Ч��ѡ�����������롣\n");
		        break;
		    }
	  }else {
	    printf("��ǰû�л��ߡ�\n");
	  }
	  	}while(deletechoice!=3); 
		break;
		
		
      case 3:;
      	int i3;
          if (patientCount > 0) {
		    printf("\n�����б�\n");
		    for (i3 = 0; i3 < patientCount; ++i3) {
		      printf("ID: %d\n", patients[i3].id);
		      printf("��������: %s\n", patients[i3].name);
		      printf("����: %d\n", patients[i3].age);
		      printf("����: %s", patients[i3].condition);
		      printf("¥��: %d\n", patients[i3].floor);
		      printf("����: %d\n", patients[i3].room);
		      printf("��λ��: %d\n", patients[i3].bedid);
		      printf("ҽ��������Ա: %s\n", patients[i3].correspondingnurse);
		      printf("-------------------------\n");
		    }
		  } else {
		    printf("��ǰû�л��ߡ�\n");
		  };
        break;
        
      case 4:;
      	int searchchoice,byid,bybedid;
		do{
	        printf("1.���봲λ�Ų���\n2.���뻼��id������Ϣ:\n0.�˳�\n");
		    scanf("%d", &searchchoice);
		if (patientCount > 0) {
		    
		    switch (searchchoice) {
			      case 1:;
			        int i; 
			      	printf("�����봲λ��\n");
			      	scanf("%d",&bybedid);
			       for(i=0;i<patientCount;++i){
				   	if(bybedid==patients[i].bedid){
				   	printf("��������: %s", patients[i].name);
					printf("����: %d\n", patients[i].age);
			        printf("����: %s\n", patients[i].condition);
			        printf("ҽ��������Ա: %s\n", patients[i].correspondingnurse);
					printf("-------------------------\n");
				   }else{if(i==patientCount)
				   	printf("����û�в���\n");
				   }}
			        break;
			      case 2:;
			      	int i2;
			      	printf("������Ҫ���ҵĲ��˵ı��\n");
			      	scanf("%d",&byid);
					for(i2=0;i2<patientCount;++i2){
					if(byid==patients[i2].id){
					printf("��������: %s", patients[i2].name);
					printf("����: %d\n", patients[i2].age);
					printf("����: %s\n", patients[i2].condition);
					printf("ҽ��������Ա: %s\n", patients[i2].correspondingnurse);
					printf("-------------------------\n");
					}else{
					printf("�ò��˱�Ų�����\n");
					}
					break;}
				  case 0:
					printf("��лʹ�ã�\n");
					break;	
			      default:
			        printf("��Ч��ѡ�����������롣\n");
			        break;
			    }
		  }else {
		    printf("��ǰû�л��ߡ�\n");
		  }
		  	}while(searchchoice!=3);
	        break;
        
	  case 5:
	    printf("���л�ʿ������������뻤ʿ����ǰ��������\n");
	    break;  
		    
	  case 0:
		printf("��лʹ�ò�������ϵͳ��\n");
		break;
		
      default:
        printf("��Ч��ѡ�����������롣\n");
    }
  } while (choice != 0);

  return 0;
}

