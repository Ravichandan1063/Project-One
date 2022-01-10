#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    fstream mainfile;
    fstream dupfile;
    fstream dupfile2;

    string a;
    char s;
    char line[100];
    char d,op;
    getline(cin,a);
    int i=1,j,lno;
    if(a.substr(0,4)!="sai "){
        cout<<"Invalid Command"<<endl;
        return 1;
    }
    for( j=4;a[j]!='\0';j++){
        i++;
    }
    char b[i];
    for( j=0;j<i;j++){
        b[j]=a[j+4];
    }
    dupfile.open("duplicate.cpp",ios::in|ios::out|ios::trunc);
    mainfile.open(b,ios::in|ios::out);
    dupfile2.open("duplicate2.cpp",ios::in|ios::out|ios::trunc);
    while (mainfile.get(s)) 
    { 
        dupfile.put(s); 
    } 
    mainfile.close();
    dupfile.close();
    while(1)
    {
        cout<<"ui?";
        d=getchar();
        cout<<d<<endl;
        switch(d){
            case 'q': //close without saving
            case 'Q': {
                        return 0;
            }
            case 'x': //save the file and close
            case 'X': {

                        ifstream read_file{"duplicate.cpp"};
                        ofstream write_file;
                        write_file.open(b,ios::out|ios::trunc);
                        while (read_file.getline(line,100)) 
                        { 
                            write_file<<line<<endl; 
                        }
                        return 0;
            }
            case 'a': //write into the file
            case 'A':{
                        cout<<"File contents:\n";
                        cin.ignore();
                        ifstream read_file{"duplicate.cpp"};
                        while (read_file.getline(line,100)) 
                        { 
                            cout<<line<<endl; 
                        }
                        read_file.close();
                        ofstream write_file;
                        write_file.open("duplicate.cpp",ios::app);
                        cout<<"enter\n";
                        cin.getline(line,100);
                        while(line[0]!='@'){
                            write_file<<line<<endl;
                            cin.getline(line,100);
                        }
                        write_file.close();
                        break;
            }
            case 'l': // insert line
            case 'L':{
                        cout<<"enter line no:"<<endl;
                        cin>>lno;
                        ifstream read_file{"duplicate.cpp"};
                        ofstream write_file;
                        write_file.open("duplicate2.cpp",ios::out);
                        for(i=1;i<lno;i++){
                            read_file.getline(line,100);
                            write_file<<line <<endl;
                        }
                        cout<<"enter text to be inserted"<<endl;
                        cin.ignore();
                        cin.getline(line,100);
                        while(line[0]!='@'){
                            write_file<<line<<endl;
                            cin.getline(line,100);
                        }
                        while (read_file.getline(line,100)) 
                        { 
                            write_file<<line<<endl; 
                        }
                        read_file.close();
                        write_file.close();
                        ifstream read_file2{"duplicate2.cpp"};
                        ofstream write_file2;
                        write_file2.open("duplicate.cpp",ios::out);
                        while (read_file2.getline(line,100)) 
                        { 
                            write_file2<<line<<endl; 
                        }
                        break;
            }
            case 'd': //delete the line
            case 'D':{
                        cout<<"enter line no:"<<endl;
                        cin>>lno;
                        ifstream read_file{"duplicate.cpp"};
                        ofstream write_file;
                        write_file.open("duplicate2.cpp",ios::out);
                        for(i=1;i<lno;i++){
                            read_file.getline(line,100);
                            write_file<<line <<endl;
                        }
                        read_file.getline(line,100);
                        while (read_file.getline(line,100)) 
                        { 
                            write_file<<line<<endl; 
                        }
                        cin.ignore();
                        read_file.close();
                        write_file.close();
                        ifstream read_file2{"duplicate2.cpp"};
                        ofstream write_file2;
                        write_file2.open("duplicate.cpp",ios::out);
                        while (read_file2.getline(line,100)) 
                        { 
                            write_file2<<line<<endl; 
                        }
                        read_file2.close();
                        write_file2.close();
                        break;  
            }
            case 'f': //find a word and enter data
            case 'F':{
                        string str; 
                        string str1; 
                        cout<<"Enter string to find:"<<endl;
                        cin>>str1;
                        size_t found = str.find(str1); 
                        ifstream read_file2{"duplicate.cpp"};
                        ofstream write_file2;
                        write_file2.open("duplicate2.cpp",ios::out|ios::trunc);
                        while(getline(read_file2,str)){
                            found = str.find(str1); 
                            if (found != string::npos){
                                break;
                            }
                            write_file2<<str<<endl;
                        } 
                        if(found == string::npos){
                            cout<<"string not found"<<endl;
                            break;
                        }
                        write_file2<<str.substr(0,found);
                        cout<<"do u want to enter anything before the word[y/n]\n";
                        cin>>s;
                        if(s=='y'||s=='Y'){
                            cout<<"enter:";
                            cin.ignore();
                            s=getchar();
                            int count=0;
                            while(1){
                                write_file2<<s;
                                s=getchar();
                                if(s=='@')break;
                            }
                            write_file2<<str.substr(found)<<endl;
                            while(getline(read_file2,str)){
                            write_file2<<str<<endl;
                            } 
                            read_file2.close();
                            write_file2.close();
                            ifstream read_file{"duplicate2.cpp"};
                            ofstream write_file;
                            write_file.open("duplicate.cpp",ios::out);
                            while (read_file.getline(line,100)) 
                            { 
                                write_file<<line<<endl; 
                            }
                            read_file.close();
                            write_file.close();
                        }
                        cin.ignore();
                        break;
            }
        }
    }
    return 0;
}  