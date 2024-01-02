#include <stdio.h>
#include <string.h>

// 定义医护人员结构体
struct MedicalStaff {
    char name[50];
    int id;
    int managedBeds[20];
};

// 全局数组存储医护人员信息
struct MedicalStaff staffArray[100];
int staffCount = 0;

int main() {
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

    return 0;
}

