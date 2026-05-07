#include<iostream>
#include<string>
#include<vector>

/*************************************************
          +-----------------+
          |   Prototype     |  <--- 可选接口
          |  +clone()       |
          +-----------------+
                    ^
                    |
          +-----------------+
          |      Hero       |
          +-----------------+
          | -name           |
          | -health         |
          | -equipments     |  // vector<Equipment*>
          | -outfits        |  // vector<Outfit*>
          +-----------------+
          | +clone()        |
          | +addEquipment() |
          | +addOutfit()    |
          +-----------------+
           /               \
          /                 \
+----------------+   +----------------+
|   Equipment    |   |     Outfit     |
+----------------+   +----------------+
| -name          |   | -name          |
| -type          |   | -type          |
| -value         |   | -color         |
+----------------+   +----------------+
| +clone()       |   | +clone()       |
+----------------+   +----------------+




**************************************************************/

class Equipment
{
private:
    std::string m_name;
    std::string m_type;
    int m_value;
public:
    Equipment(const std::string& name,const std::string& type,int value):m_name(name),m_type(type),m_value(value){}
    Equipment(const Equipment& other):m_name(other.m_name),m_type(other.m_type),m_value(other.m_value){}
    Equipment* clone() const { return new Equipment(*this); }
    inline const std::string& GetName() { return m_name; }
    inline const std::string& GetType() { return m_type; }
    inline const int GetValue() { return m_value; }
    inline void SetName(const std::string& name) { m_name = name; }
    inline void SetType(const std::string& type) { m_type = type; }
    inline void SetValue(int value) { m_value = value; }
    void show() const { std::cout << "Equipment name :" << m_name << "m_type :" << m_type << "value :" << m_value << std::endl; }
};

class Qutfit
{
private:
    std::string m_name;
    std::string m_type;
    std::string m_color;
public:
    Qutfit(const std::string& name, const std::string& type, const std::string& color) :m_name(name), m_type(type), m_color(color) {}
    Qutfit(const Qutfit& other) :m_name(other.m_name), m_type(other.m_type), m_color(other.m_color) {}
    Qutfit* clone() const { return new Qutfit(*this); }
    inline const std::string& GetName() { return m_name; }
    inline const std::string& GetType() { return m_type; }
    inline const std::string& GetColor() { return m_color; }
    inline void SetName(const std::string& name) { m_name = name; }
    inline void SetType(const std::string& type) { m_type = type; }
    inline void SetColor(const std::string& color) { m_color = color; }
    void show() const { std::cout << "Equipment name :" << m_name << "m_type :" << m_type << "m_color :" << m_color << std::endl; }
};



class Hero
{
private:
    std::string m_name;
    int m_health;
    std::vector<Equipment*>m_equiments;
    std::vector<Qutfit*>m_qutfits;
public:
    Hero(const std::string& name,int health):m_name(name),m_health(health){}
    Hero(const Hero& other) :m_name(other.m_name), m_health(other.m_health)
    {
        for (auto e : other.m_equiments )
        {
            m_equiments.push_back(e->clone());
        }
        for (auto q : other.m_qutfits)
        {
            m_qutfits.push_back(q->clone());
        }

    }
    ~Hero()//建议清空 vector，避免 dangling pointer：
    {
        for (auto e : m_equiments) delete e;
        m_equiments.clear();
        for (auto q : m_qutfits) delete q;
        m_qutfits.clear();
    }
    Hero* clone() const { return new Hero(*this); }//clone 不修改原对象，应该声明为 const，这样调用时可以对 const Hero 对象使用。

    void SetName(const std::string& name) { m_name = name; } //这里应该用 const std::string&，否则传临时对象会报错：
    const std::string& GetName() { return m_name; } //这样会暴露内部成员，可以被直接修改。建议提供 const 版本：

    void SetHealth(int hea) { m_health = hea; }
    int GetHealth() { return m_health; }

    void addEquipment(Equipment* e) { m_equiments.push_back(e->clone()); }
    void addQutfit(Qutfit* q) { m_qutfits.push_back(q->clone()); }

    void show() const {
        std::cout << "hero name :" << m_name << "health :" << m_health << std::endl;
        for (auto e : m_equiments)
        {
            e->show();
        }
        for (auto q : m_qutfits) q->show();
    }
};



int main()
{
    //创建基础服装
    Qutfit* q1 = new Qutfit("maozi", "head", "red");
    Qutfit* q2 = new Qutfit("xiezi", "jiao", "grreen");

    Equipment* e1 = new Equipment("jian", "wuqi", 100);
    Equipment* e2 = new Equipment("toukui", "fangyu", 30);

    Hero* base = new Hero("mimi", 200);
    base->addEquipment(e1);
    base->addEquipment(e2);
    base->addQutfit(q1);
    base->addQutfit(q2);


    Hero* base2 = base->clone();
    base2->SetName("haixiao");
    base2->addEquipment(new Equipment("gongjian", "wuqi", 10));



    
    base->show();

    base2->show();


    delete q1;
    delete q2;
    delete e2;
    delete e1;
    delete base;
    delete base2;
	std::cout << "hello" << std::endl;
	return 0;
}