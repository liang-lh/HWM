#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 数据结构定义
// ...（之前的结构定义）

// 费用信息节点
typedef struct {
	int id;
	float amount;
	char payWay;
} Cost;

typedef struct CostNode {
	Cost cost;
	struct CostNode *next;
} CostNode;

CostNode *costHead = NULL; // 费用链表头部

// 费用管理菜单显示




int main () {
	int choice;

	while (1) {
		printf("\n费用管理系统\n");
		printf("1. 添加费用单\n");
		printf("2. 删除费用单\n");
		printf("3. 更新费用\n");
		printf("4. 查询费用\n");
		printf("5. 列出所有费用单\n");
		printf("0. 返回主菜单\n");

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
	return 0;
}
