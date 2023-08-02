library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity banco_registradores is
    port (
        i_CLK         :in std_logic;
        i_RST         :in std_logic;
        i_REG_WR    :in std_logic;                          --signal for write in register
        i_RS1  :in std_logic_vector(4 downto 0);       --address of rs1
        i_RS2  :in std_logic_vector(4 downto 0);       --address of rs2
        i_RD  :in std_logic_vector(4 downto 0);       --address of rd
        i_DATA        :in std_logic_vector(31 downto 0);      --i_DATA to be written
        o_RS1   :out std_logic_vector(31 downto 0);     --i_DATA in rs1
        o_RS2   :out std_logic_vector(31 downto 0)      --i_DATA in rs2
    );
end entity banco_registradores;

architecture arch_banco_registradores of banco_registradores is

    type Mem is array(0 to 31) of std_logic_vector(31 downto 0);    --Mem is an array of 32 registers of 32 bits
    signal registers : Mem := (others => (others => '0'));          --registers is a Mem

begin
    process( i_CLK, i_RST, i_REG_WR, i_RS1, i_RS2, i_RD, i_DATA, registers )
    begin
        if i_RST = '0' then
            registers <= (others => (others => '0'));
        elsif rising_edge(i_CLK) then               
            if i_REG_WR = '1' and i_RD /= "00000" then         --check for write register and destiny diff from address zero
                registers(conv_integer(i_RD)) <= i_DATA;       --write i_DATA to destiny register
            end if;
        end if ;
    end process ;

    o_RS1 <= registers(conv_integer(i_RS1)) when i_RS1 /= "00000" else (others => '0');   --asynchronic read from rs1
    o_RS2 <= registers(conv_integer(i_RS2)) when i_RS2 /= "00000" else (others => '0');   --asynchronic read from rs2

end arch_banco_registradores ; -- arch_Reg_File