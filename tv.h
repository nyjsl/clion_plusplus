
//
// Created by xiaolian on 2020/11/13.
//

#ifndef CLION_CPLUSPLUS_TV_H
#define CLION_CPLUSPLUS_TV_H

class Tv; // forward declatartion
class Remote{
public:
    enum {Off,On};
    enum {MinVal,MaxVal = 20};
    enum {Anteena,Cable};
    enum {TV, DVD};

private:
    int mode;
public:
    Remote(int m = TV):mode(m){}
    //prototype only
    bool volup(Tv &t);
    bool voldown(Tv &t);
    void onOff(Tv &t);
    void chanup(Tv &t);
    void chandown(Tv &t);
    void set_mode(Tv &t);
    void set_input(Tv &t);
    void set_chan(Tv &t,int c);
};

class Tv{
private:
    int state; // on or of
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    //Remote can access TV private parts
    /**
     * 友元类的所有方法都可以访问原始类的私有成员和保护恒源
     * 另外也可以做更严格的限制,只讲特定的成员函数指定为另一个类的友元
     */
    friend void Remote::set_chan(Tv &t, int c) ;
    enum {Off,On};
    enum {MinVal,MaxVal = 20};
    enum {Anteena,Cable};
    enum {TV, DVD};
    Tv(int s = Off,int mc = 125):
    state(s),volume(5),maxchannel(mc),channel(2),mode(Cable),input(TV){}

    void onOff(){state = (state == On)? Off:On;}
    bool ison()const{return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode(){ mode = (mode == Anteena)? Cable : Anteena; }
    void set_input(){ input = (input == TV) ? DVD : TV; }
    void settings()const; // display all settings

};

//Remote methods as inline functions

inline bool Remote::volup(Tv &t) {
    return t.volup();
}

inline bool Remote::voldown(Tv &t) {
    return t.voldown();
}

inline void Remote::onOff(Tv &t) {
    t.onOff();
}

inline void Remote::chanup(Tv &t) {
    t.chanup();
}

inline void Remote::chandown(Tv &t) {
    t.chandown();
}

inline void Remote::set_mode(Tv &t) {
    t.set_mode();
}

inline void Remote::set_input(Tv &t) {
    t.set_input();
}

inline void Remote::set_chan(Tv &t, int c) {
    t.channel = c;
}



#endif //CLION_CPLUSPLUS_TV_H
