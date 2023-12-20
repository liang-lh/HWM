#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���ݽṹ����
// ...��֮ǰ�Ľṹ���壩

// ������Ϣ�ڵ�
typedef struct {
	int id;
	float amount;
	char payWay;
} Cost;

typedef struct CostNode {
	Cost cost;
	struct CostNode *next;
} CostNode;

CostNode *costHead = NULL; // ��������ͷ��

// ���ù���˵���ʾ




int main () {
	int choice;

	while (1) {
		printf("\n���ù���ϵͳ\n");
		printf("1. ��ӷ��õ�\n");
		printf("2. ɾ�����õ�\n");
		printf("3. ���·���\n");
		printf("4. ��ѯ����\n");
		printf("5. �г����з��õ�\n");
		printf("0. �������˵�\n");

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
	return 0;
}
