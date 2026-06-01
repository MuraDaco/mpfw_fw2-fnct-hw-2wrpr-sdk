#ifdef      DEBUG_DEF_HW_2_USART_CMMN_CPP
    {
        static uint8_t l_cnt = 0;
        //              0    5    1    5    2    5    3    5    4
        char l_str[] = "DEBUG - hw2UsartCmmn - TOKEN_1";
        if(g_debug)       {
            l_str[32] = 'A';
        } else {
            l_str[32] = 'B';
        }
        l_cnt++;
        sysDebug_t::msg(54,4, l_str);

    }

#endif  //  DEBUG_DEF_HW_2_USART_CMMN_CPP
