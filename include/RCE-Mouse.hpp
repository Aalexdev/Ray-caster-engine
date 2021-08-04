#ifndef  __RC_MOUSE__HPP__
    #define __RC_MOUSE__HPP__

    #include "RCE-begin_code.hpp"
    
    namespace RCE{
        namespace events{
            class Mouse{
                public:
                    Mouse();
                    ~Mouse();

                    enum Button_enum{
                        BTN_LEFT,
                        BTN_MIDDLE,
                        BTN_RIGHT
                    };

                    struct Button{
                        bool left;
                        bool middle;
                        bool right;
                    };

                    /**
                     * @brief get if the input button is pushed
                     * @param button the button
                     * @return true if pushed false otherwise
                     */
                    bool is_btn_pushed(Button_enum button);

                    /**
                     * @brief get if the input button is down
                     * @param button the button
                     * @return true if down false otherwise
                     */
                    bool is_btn_down(Button_enum button);

                    /**
                     * @brief get if the input button is up
                     * @param button the button
                     * @return true if up false otherwise
                     */
                    bool is_btn_up(Button_enum button);

                    /**
                     * @brief get the x of the mouse (relative to the window)
                     * @return the mouse x
                     */
                    const int get_x(void);

                    /**
                     * @brief get the y of the mouse (relative to the window)
                     * @return the mouse y
                     */
                    const int get_y(void);

                    /**
                     * @brief get the mouse position
                     * 
                     * @param x the pointer to the x, nullptr if not used
                     * @param y the pointer to the y, nullptr if not used
                     */
                    void get_pos(int *x, int *y);

                    void OnEvent(void *e);
                    void OnTick(void);

                private:
                    Button up;
                    Button down;
                    Button pushed;

                    int x, y;
                    bool wheel_up, wheel_down;
            };
        }
    }

#endif