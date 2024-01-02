#include <stdio.h>
#include <string.h>

// ����ҽ����Ա�ṹ��
struct MedicalStaff {
    char name[50];
    int id;
    int managedBeds[20];
};

// ȫ������洢ҽ����Ա��Ϣ
struct MedicalStaff staffArray[100];
int staffCount = 0;

int main() {
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

    return 0;
}

