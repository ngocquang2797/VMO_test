#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <math.h>
#include <vector>
#include <list>

using namespace std;


class Student{
public:
	string name;
	int age;
	int math;
	int physical;
	int chemistry;

	Student(string n, int a, int m, int p, int c){
		name=n;
		age=a;
		math=m;
		physical=p;
		chemistry=c;
	}
// b tính average
	float avg(){
		return (math+chemistry+physical)/3;
	}
// b xep hang student
	string rank(){
		float average = (math+chemistry+physical)/3;
		if(average >=8.0) return "GIOI";
		else if(average >= 6.5) return "KHA";
		else if(average >= 5.0) return "TB";
		else return "YEU";
	}

};

class ManageStudent{
public:
	list<Student> students;

// c find student have name = string
	Student find(string Name){
		std::list<Student>::iterator it;

		for (it=students.begin(); it!=students.end(); ++it){
			Student s = *it;
			if(s.name == Name) return s;
		}
	}
	// d list of student have rank ....
	list<Student> searchRank(string r){
		list<Student> stu;

		std::list<Student>::iterator it;

		for (it=students.begin(); it!=students.end(); ++it){
			Student s = *it;
			if(s.rank() == r){
				stu.push_back(s);
			}
		}
		return stu;
	}
// e

	
};

int main() {

	ManageStudent m;
	// a
	m.students = {Student("TUNG", 19,2,3,4), Student("ANH", 19,2,3,4), Student("AANN", 19,2,3,4), Student("HUNG", 19,2,3,4), Student("HIEU", 19,2,3,4)};
	m.students.push_back(Student("QUANG", 18,9,10,10));
	m.students.push_back(Student("THUC", 19,2,3,4));
	m.students.push_back(Student("HIEN", 19,2,3,4));
	// cout<<m.students.name;


	Student q = m.find("QUANG");
	cout<<q.age<<endl;
	
    // freopen("F:\\Code\\C++\\VMO\\tst.txt", "r", stdin);
    

    return 0;
}