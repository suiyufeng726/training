#include <string>  
#include <iostream>  

using namespace std;  

#include "cmd.h" 

int CShell::ParseCmd(string name)  
{  
	vector<CCmd*>* cmdlist = (vector<CCmd*>*)&m_veCCmdList;
	vector<CCmd*>::iterator iter = cmdlist->begin();  
	while(iter != cmdlist->end())  
	{  
		CCmd* cmd = *iter;
		if (*cmd==name/*->GetName()*/) {
			cout << "supported command" << endl;
			cmd->Run();
			break;  
		}
		iter++;
	}

	if (iter == cmdlist->end())
		cout << "not supported cmd" << endl;

	return 0;  
}  

int CShell::AddCmd(CCmd *cmd)  
{  
	this->m_veCCmdList.push_back(cmd);   
	return 0;  
}

CShell::CShell()
{
}

CShell * CShell::GetInstance()
{
	static CShell m_Instance;
	return &m_Instance;
}
