//�����˱�ʾ�Ǹ����������������ֶ���������洢�ģ�����ÿ���ڵ㶼����һ���������֣���������ӣ�����һ��������ʽ���ؽ��
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



