//给定了表示非负数的两个链表，数字都是以逆序存储的，并且每个节点都包含一个单个数字，将两数相加，并以一个链表形式返回结果
struct ListNode{
    int value;
    ListNode* next;
};
ListNode *addtwonums(ListNode *l1,ListNode *l2)
{
	ListNode *result=new ListNode();
	result->value=-1;
	ListNode *pre=result;
	ListNode *pa=l1,*pb=l2;
	int carry=0;
	while(pa!=NULL ||  pb!=NULL)
	{
		int av=pa==NULL? 0:pa->value;
		int bv=pb==NULL? 0:pb->value;
		ListNode *node=new ListNode();
		node->value=(av+bv+carry)%10;
		carry=(av+bv+carry)/10;
		pre->next=node;
		pre=pre->next;
		pa=pa==NULL? 0:pa->next;
		pb=pb==NULL? 0:pb->next;
	}
	if(carry>0)
	{
		pre->next=new ListNode();
		pre->next->value=1;
	}
	pre=result->next;
	delete result;
	return pre;
}



