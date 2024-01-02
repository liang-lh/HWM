#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>


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

// ҽ����Ա��Ϣ 
struct MedicalStaff {
    char name[50];
    int id;
    int managedBeds[20];
};

struct MedicalStaff staffArray[100];
int staffCount = 0;


// ������Ϣ
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
printf("����������ʹ�õĹ���: ");

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
    
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    char time_string[100];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
    
    FILE* f;
    f = fopen("log.txt", "a+");
    if (f != NULL)
    {
        fprintf(f, "%s ����id:%d ��������:%ls �����Ա�:%ls ��������:%d\n", time_string, newNode->id, newNode->name, newNode->gender, newNode->age);
        fclose(f);
        f=NULL;
    }

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

void costManager() {
	int choice;

	while (1) {
		printf("------------------\n");
		printf("���ù�����棺\n");
		printf("1. ��ӷ��õ�\n");
		printf("2. ɾ�����õ�\n");
		printf("3. ���·���\n");
		printf("4. ��ѯ����\n");
		printf("5. �г����з��õ�\n");
		printf("0. �������˵�\n");
		printf("------------------\n");

		printf("����������ʹ�õĹ���: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:; // ��ӷ���
				CostNode *newCostNode = (CostNode *)malloc(sizeof(CostNode));
			
				printf("�������id: ");
				scanf("%d", &newCostNode->cost.id);
			
				printf("������ķ���: ");
				scanf("%f", &newCostNode->cost.amount);
			
				printf("��ѡ������ʹ�õ�֧������(1Ϊ�ֽ�, 2Ϊ���ÿ�, 3Ϊ����): ");
				scanf(" %c", &newCostNode->cost.payWay);
				
				time_t current_time = time(NULL);
			    struct tm *local_time = localtime(&current_time);
			    char time_string[100];
			    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);

				FILE* f;
			    f = fopen("log.txt", "a+");
			    if (f != NULL)
			    {
			        fprintf(f, "%s ����id:%d ���߷���:%f ����֧������:%c\n", time_string, newCostNode->cost.id, newCostNode->cost.amount, newCostNode->cost.payWay);
			        fclose(f);
			        f=NULL;
			    }
			
			
				// ���·��ýڵ��������ͷ��
				newCostNode->next = costHead;
				costHead = newCostNode;
				printf("������!\n");
				break;

			case 2:; // ɾ������
				int costID;
				printf("��������Ҫɾ����id: ");
				scanf("%d", &costID);
			
				CostNode *current = costHead;
				CostNode *prev = NULL;
			
				// ���������ҵ�Ҫɾ���Ľڵ�
				while (current != NULL && current->cost.id != costID) {
					prev = current;
					current = current->next;
				}
			
				if (current == NULL) {
					printf("�Ҳ�����\n");
					return;
				}
			
				// ���ڵ���������Ƴ�
				if (prev == NULL) {
					// ɾ������ͷ�ڵ�
					costHead = current->next;
				} else {
					prev->next = current->next;
				}
			
				free(current);
				printf("ɾ���ɹ�\n");
				break;

			case 3:; // ���·���
				int costID3;
				printf("����������µ�id: ");
				scanf("%d", &costID3);
			
				CostNode *current3 = costHead;
			
				// ���������ҵ�Ҫ���µĽڵ�
				while (current3 != NULL && current3->cost.id != costID3) {
					current3 = current3->next;
				}
			
				if (current3 == NULL) {
					printf("�Ҳ���!\n");
					return;
				}
			
				// ��ȡ�µķ�����Ϣ
				printf("�������: ");
				scanf("%f", &current->cost.amount);
			
				printf("����һ���µ�֧��ʽ (1Ϊ�ֽ�, 2Ϊ���ÿ�, ����Ϊ����): ");
				scanf(" %c", &current->cost.payWay);
			
				printf("�������\n");
				break;

			case 4:; // ��������
				int costID4;
				printf("���������ѯ��id: ");
				scanf("%d", &costID4);
			
				CostNode *current4 = costHead;
			
				// ���������ҵ�Ҫ�����Ľڵ�
				while (current4 != NULL && current4->cost.id != costID4) {
					current4 = current4->next;
				}
			
				if (current4 == NULL) {
					printf("�Ҳ���!\n");
					return;
				}
			
				// ��ӡ������Ϣ
				printf("���÷��֣� - ID: %d, ���: %.2f, ֧����ʽ: %c\n", current4->cost.id, current4->cost.amount,
				       current4->cost.payWay);
				break;

			case 5:; // �г����з���
				CostNode *current5 = costHead;
				printf("\n���з�����Ϣ������\n");
				while (current5 != NULL) {
					printf("ID: %d, ���: %.2f, ֧����ʽ: %c\n", current5->cost.id, current5->cost.amount, current5->cost.payWay);
					current5 = current5->next;
				}
				break;

			case 0:
				return; // ������һ��˵�

			default:
				printf("û�����ѡ����!\n");
		}
	}
}

void bedManager() {
	  int choice;

  do {
    // ��ʾ�˵�
    printf("------------------\n");
    printf("����������棺\n");
    printf("1. ��ӻ���\n");
	printf("2. ɾ������\n");
    printf("3. ��ʾ�����б�\n");
    printf("4. ���һ�����Ϣ\n");
    printf("5. ���л�ʿ\n");
    printf("0. �˳�\n");
    printf("------------------\n");
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
		scanf("%d", &newPatient.bedid);time_t current_time = time(NULL);
		
	    struct tm *local_time = localtime(&current_time);
	    char time_string[100];
	    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", local_time);
	    
		while (getchar() != '\n'); // ������뻺����
		
		printf("�����뻼�߶�Ӧ�Ļ�ʿ: ");
	    fgets(newPatient.correspondingnurse, sizeof(newPatient.correspondingnurse), stdin);
	    
	    
		FILE* f;
	    f = fopen("log.txt", "a+");
	    if (f != NULL)
	    {
	        fprintf(f, "%s ����id:%d ��������:%s ��������:%d ���߲���:%s ��������¥��:%d �������ڷ���:%d ���ߵĴ�λ��:%d ���߶�Ӧ�Ļ�ʿ:%s\n", time_string, newPatient.id, newPatient.name, newPatient.age, newPatient.condition, newPatient.floor, newPatient.room, newPatient.bedid, newPatient.correspondingnurse);
	        fclose(f);
	        f=NULL;
	    }
	
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
        printf("1.���봲λ�Ų���\n2.���뻼��id������Ϣ:\n0.�˳�\n");
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
	  	}while(deletechoice!=0); 
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
			      	printf("������Ҫ���ҵĲ��˵�ID��\n");
			      	scanf("%d",&byid);
					for(i2=0;i2<patientCount;++i2){
					if(byid==patients[i2].id){
					printf("��������: %s", patients[i2].name);
					printf("����: %d\n", patients[i2].age);
					printf("����: %s\n", patients[i2].condition);
					printf("ҽ��������Ա: %s\n", patients[i2].correspondingnurse);
					printf("-------------------------\n");
					}else{
					printf("�ò���ID������\n");
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
		  	}while(searchchoice!=0);
	        break;
        
	  case 5:
	    printf("���л�ʿ������������뻤ʿ����ǰ��������\n");
	    break;  
		    
	  case 0:
		break;
		
      default:
        printf("��Ч��ѡ�����������롣\n");
    }
  } while (choice != 0);

	
}

void staffManager(){
    int choice;

    do {
        // ��ʾ�˵�
        printf("\nҽ����Ա����ϵͳ\n");
        printf("1. ¼��ҽ����Ա��Ϣ\n");
        printf("2. ��ѯҽ����Ա��Ϣ\n");
        printf("3. �޸�ҽ����Ա��Ϣ\n");
        printf("4. ɾ��ҽ����Ա��Ϣ\n");
        printf("0. �˳�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        // �����û�ѡ��ִ����Ӧ����
        switch (choice) {
        case 1:; 
            struct MedicalStaff newStaff;

		    // ����ҽ����Ա��Ϣ
		    printf("\n������ҽ����Ա��Ϣ:\n");
		    printf("����: ");
		    scanf("%s", newStaff.name);
		    printf("ID: ");
		    scanf("%d", &newStaff.id);
		
		    // ¼�벡����Ϣ
		    printf("������IDΪ%d��ҽ����Ա����Ĵ�λ��Ϣ��0��ʾδ����1��ʾ����:\n", newStaff.id);
		    int i; 
		    for (i = 0; i < 20; i++) {
		        printf("��λ%d: ", i + 1);
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
		        fprintf(f, "%s ����:%s ID:%d ", time_string, newStaff.name, newStaff.id);
		        fprintf(f, "ҽ����Ա����Ĵ�λ��Ϣ��0��ʾδ����1��ʾ����:");
		        int h;
		        for (h = 0; h < 20; h++){
		        	fprintf(f, "%d", newStaff.managedBeds[h]);
				}   
				fprintf(f, "\n");
		        fclose(f);
		        f=NULL;
		    }
		
		    // ���µ�ҽ����Ա��ӵ�������
		    staffArray[staffCount++] = newStaff;
		
		    printf("ҽ����Ա��ӳɹ���\n");;
            break;
        case 2:
                if (staffCount == 0) {
		        printf("����ҽ����Ա��Ϣ��\n");
		        return;
		    }
		
		    // �������鲢��ʾҽ����Ա��Ϣ
		    printf("\nҽ����Ա��Ϣ:\n");
		    int i2;
		    for (i2 = 0; i2 < staffCount; i2++) {
		        printf("����: %s\n", staffArray[i2].name);
		        printf("ID: %d\n", staffArray[i2].id);
		        printf("����Ĵ�λ: ");
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
		        printf("����ҽ����Ա��Ϣ��\n");
		        return;
		    }
		
		    // ����Ҫ���µ�ҽ����Ա��ID
		    printf("\n������Ҫ���µ�ҽ����Ա��ID: ");
		    scanf("%d", &targetId);
		
		    // �������в���ҽ����Ա
		    int index = -1;
		    int i3;
		    for (i3 = 0; i3 < staffCount; i3++) {
		        if (staffArray[i3].id == targetId) {
		            index = i3;
		            break;
		        }
		    }
		
		    // ����ҵ�ҽ����Ա���������Ϣ
		    if (index != -1) {
		        printf("�������µ�����: ");
		        scanf("%s", staffArray[index].name);
		
		        // ¼���µĲ�����Ϣ
		        printf("������IDΪ%d��ҽ����Ա����Ĵ�λ��Ϣ��0��ʾδ����1��ʾ����:\n", targetId);
		        int i3;
		        for (i3 = 0; i3 < 20; i3++) {
		            printf("��λ%d: ", i3 + 1);
		            scanf("%d", &staffArray[index].managedBeds[i]);
		        }
		
		        printf("ҽ����Ա��Ϣ���³ɹ���\n");
		    }
		    else {
		        printf("δ�ҵ�IDΪ%d��ҽ����Ա��\n", targetId);
		    }
            break;
        case 4:;
            int targetId4;
		
		    if (staffCount == 0) {
		        printf("����ҽ����Ա��Ϣ��\n");
		        return;
		    }
		
		    // ����Ҫɾ����ҽ����Ա��ID
		    printf("\n������Ҫɾ����ҽ����Ա��ID: ");
		    scanf("%d", &targetId4);
		
		    // �������в���ҽ����Ա
		    int index4 = -1;
		    int i4;
		    for (i4 = 0; i4 < staffCount; i4++) {
		        if (staffArray[i4].id == targetId4) {
		            index4 = i4;
		            break;
		        }
		    }
		
		    // ����ҵ�ҽ����Ա����ɾ����Ϣ
		    if (index4 != -1) {
		        // �������Ԫ����ǰ�ƶ�������Ҫɾ����Ԫ��
		        int i;
		        for (i = index4; i < staffCount - 1; i++) {
		            staffArray[i] = staffArray[i + 1];
		        }
		        staffCount--;
		        printf("IDΪ%d��ҽ����Ա��Ϣɾ���ɹ���\n", targetId4);
		    }
		    else {
		        printf("δ�ҵ�IDΪ%d��ҽ����Ա��\n", targetId4);
		    }
            break;
        case 0:
            printf("�����˳������ټ���\n");
            break;
        default:
            printf("��Ч��ѡ�������ԡ�\n");
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

    //����case����
    
    default:
      printf("û�����ѡ����!\n");
  }

  menu();
  scanf("%d", &choice);
  }

  return 0;
  }

  
