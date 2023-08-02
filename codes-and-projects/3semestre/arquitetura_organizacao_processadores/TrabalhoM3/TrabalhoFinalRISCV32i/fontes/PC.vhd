--PC is a register that is going to be updated with the value of the input
--every time there is a rising edge if clk_man is disable.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity PC is
    port (
        i_PC    : in std_logic_vector(31 downto 0);
        i_CLK     : in std_logic;
        i_RST     : in std_logic;
        o_PC   : out std_logic_vector(31 downto 0)
    );
end entity PC;

architecture arch_PC of PC is

begin
    process( i_CLK, i_RST)
    begin
        if i_RST = '0' then
            o_PC <= (others => '0');
        else
            if rising_edge(i_CLK) then        
                    o_PC <= i_PC;          --register operation
            end if;
        end if;
    end process ;
end arch_PC ; -- arch_PC