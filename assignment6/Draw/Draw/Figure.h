#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <string>

class BlackBoard; 

/// @brief [��ĸ�Ҫ����]
///
/// [���������.]
///
/// @see 
///
class Figure
{
public:
    // Figure����������
    virtual ~Figure() { }
 
    // Figure��ӿ�.
public:
    // ����Figure�����඼���ṩ�������ӿڣ�
    // �Ӷ�ʹʹ���ߣ�FigureManager������������
    // �ڲ�ͬ�Ļ�ͼ���͵�ʵ��
    // ������ = ��֪��
    // ��֪�� = ��չ�������
    virtual void draw(BlackBoard &) = 0; 
    virtual void input(std::istream &is) = 0; 

}; // class Figure�ඨ�����.

// Factory Pattern
class FigureFactory
{
public:
    FigureFactory(const std::string &name, int id) 
        : _name(name), _id(id) { }

    int id() { return _id; } 
    const std::string &name() { return _name; }

    virtual Figure *createFigure() = 0; 

private:
    std::string _name; 
    int _id; 
};

// ����ʵ�ֱ�������̬
// �Ӷ��򻯶Թ�����Ĺ���
template<class T>
class Factory : public FigureFactory
{
public:
    Factory(const std::string name, int id) 
        : FigureFactory(name, id) { }

    virtual Figure *createFigure()
    {
        return new T; 
    }
};


#endif // #ifndef _FIGURE_H_
