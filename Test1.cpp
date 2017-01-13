int main (int argc, char* argv[])
{

	FILE* out;
	FILE* in;
	FILE* in2;
	
	
	ofstream f2;
	char* s,s1;
	string str1,str2;



	cout<<"LOADING....DONE"<<endl;

  ifstream f ("out.txt");
  ifstream f1 ("in.txt");
 
  
      
	getline (f,str1);
    getline (f1,str2);
	if (str1==str2) cout<<"GOOD";
	//cout << str1 << endl;
    
    f.close();
	f1.close();
  }

	//out = fopen("dic.txt", "w");
	//in = fopen("in.txt", "r");
	//in2 = fopen(argv[3], "r");
	
	//fgets (str,sizeof(str),in);
	//fgets (str1,sizeof(str1),out);

	//if (str==str1) cout<<"MOLODEC";

/*
	sum=0;
	while(!feof(in))
	{
		s = fgets (str,sizeof(str),in);
		int i=0;
		while(!feof())
		cout<<"POTOK1"<<endl;
	}

	fclose(in);

	ss << sum;
	s1 = ss.str();
	ss.clear();
	f1.open("out.txt", ios_base::app);
	f1<<s1<<"\n";

*/


