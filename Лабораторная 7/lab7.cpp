#include <iostream>
#include <stack>
#include<ctime>
#include<queue>
using namespace std;
struct students
{
	string name="";
	int assessment = 0;

};
struct list {
	int field;
	struct list* ptr;
};
struct list* init(int a)
{
	struct list* lst;
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->ptr = NULL;
	return(lst);
}
struct queueue {
	struct list* frnt, * rear;
};
void init(struct queueue* q) {
	q->frnt = 0;
	q->rear = 0;
}
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->ptr;
	lst->ptr = temp;
	temp->field = number;
	temp->ptr = p;
	return(temp);
}
int isempty(struct queueue* q) {
	if (q->frnt == 0)
		return 1;
	else
		return 0;
}
void insert(struct queueue* q, float x) {
	if ((q->rear == 0) && (q->frnt == 0)) {
		q->rear = init(x);
		q->frnt = q->rear;
	}
	else
		q->rear = addelem(q->rear, x);
}
void print(struct queueue* q) {
	struct list* h;
	if (isempty(q) == 1) {
		cout<<"Очередь пуста!\n"<<endl;
		return;
	}
	for (h = q->frnt; h != NULL; h = h->ptr)
	cout<< h->field<<endl;
	return;
}
int remove(struct queueue* q) {
	struct list* temp;
	int x;
	if (isempty(q) == 1) {
		cout<<"Очередь пуста!\n"<<endl;
		return 0;
	}
	x = q->frnt->field;
	temp = q->frnt;
	q->frnt = q->frnt->ptr;
	free(temp);
	return x;
}
int test(struct queueue* q) {
	int x;
	x = q->frnt->field;
	return x;
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "введите номер задания" << endl;
	int inputtasknumber = 0;
	cin >> inputtasknumber;
	if (inputtasknumber == 1)
	{
		cout << "задание: создать стек информационными полями которого являются фамилия и средний бал студента.\n добавить в стек сведение о новом студенте. организовать просмотр данных" << endl;
		stack<students> db;
		cout << "Введите количество студентов" << endl;
		int number = 0;
		char k = 'k';
		cin >> number;
		cout << "до записи в стек" << endl;
		for (size_t i = 0; i < number; i++)
		{
			students temp;

			temp.name = "test" + string(1, k);
			temp.assessment = rand() % 5;
			db.push(temp);
			cout << temp.name << endl;
			cout << temp.assessment << endl;
			k++;

		}
		cout << "после записи в стек" << endl;
		for (size_t i = 0; i < number; i++)
		{

			cout << db.top().name << endl;
			cout << db.top().assessment << endl;
			db.pop();

		}

	}
	else if (inputtasknumber == 2)
	{
		struct queueue* q;
		float a;
		q = (queueue*)malloc(sizeof(queueue*));
		init(q);
		print(q);
		for (int i = 0; i < 5; i++) {
			cout << "Введите элемент очереди: " << endl;
			cin >> a;
			insert(q, a);
		}
		cout << endl;;
		print(q);
		for (size_t i = 0; i < 2; i++)
		{
		cout<<"удаленный елемент"<<remove(q)<<endl;
		}
		cout << "Введите элемент очереди: " << endl;
		cin >> a;
		insert(q, a);

		print(q);
		float summa = 0;
		struct list* h;
		for (h = q->frnt; h != NULL; h = h->ptr)
			summa+= h->field;
		cout << "сумма всех элементов очереди " << summa << endl;
	}


			

	
	else if (inputtasknumber == 3)
	{
		cout << "ведите 10 целых чисел" << endl;
		int number[10];
		for (size_t i = 0; i < 10; i++)
		{
			cin >> number[i];
		}
		queue<int> first;
		queue<int> second;
		for (size_t i = 0; i < 10; i++)
		{
			if (number[i] % 2 == 0)
				first.push(number[i]);
			else
				second.push(number[i]);
		}
		cout << "первый элемент 1 очереди ";
		if (first.empty())
			cout << "NULL" << endl;
		else
		{
			cout << first.front() << endl;
		}
		cout << "\nпоследний элемент 1 очереди " ;
		if (first.empty())
			cout << "NULL" << endl;
		else
		{
			cout << second.back() << endl;
		}
		cout << "первый элемент 2 очереди ";
		if (second.empty())
			cout << "NULL"<<endl;
		else
		{
			cout << second.front() << endl;
		}
		cout << "\nпоследний элемент 2 очереди " ;
		if (second.empty())
			cout << "NULL" << endl;
		else
		{
			cout << second.back() << endl;
		}
		

	}
	else
	{
		cout << "Вы ввели не то число" << endl;
	}
	return 0;
}