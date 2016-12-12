#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include <vector>

class BlackBoard; 
class Figure; 
class FigureFactory; 
/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class FigureManager
{
    typedef std::vector<Figure *> Figures; 
    typedef std::vector<FigureFactory *> Factories; 

public:
	static FigureManager &handle()
	{
		static FigureManager manager; 
		return manager; 
	}

    
    // FigureManager����������
    virtual ~FigureManager() { }
 
    // FigureManager��ӿ�.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 
    void installFactory(FigureFactory *factory)
    {
        factories.push_back(factory); 
    }

    int assignID()
    {
        return ++_lastID; 
    }
    // FigureManager��protected��Ա����.
protected:
	    
    // FigureManager��protected�ͳ�Ա����.
protected:
	// FigureManager�๹�캯��.
	FigureManager() : _lastID(0) { }

     ///< ������ĳ�Ա��������û�У���ɾ������. 
    Figures _figures; 
    Factories factories; 

    int _lastID; 

}; // class FigureManager�ඨ�����.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
