#pragma once

struct windowSize{
    unsigned int width;
    unsigned int height;
    windowSize createWindowSize (unsigned int Width,unsigned int Height)
    {
        windowSize size;
        size.width = Width;
        size.height = Height;
        return size;
    }
};

class Window {
    public:
    Window(){}
    Window(windowSize screenSize){
        m_windowSize = screenSize;
        initializeSize = true;
    }
    void createWindow(windowSize screenSize){
        m_windowSize = screenSize;
        initializeSize = true;
    }
    windowSize getWindowSize(){
        if (initializeSize)
            return m_windowSize;    
    }
    windowSize setWindowSize (unsigned int Width,unsigned int Height)
    {
        windowSize size;
        size.width = Width;
        size.height = Height;
        return size;
    }
    virtual void render() = 0; 
    virtual void update() = 0;

    private:
    windowSize m_windowSize;
    bool initializeSize = false;

};