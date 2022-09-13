class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        // Using the hexadecimal system for mask utility
        int mask1 = 0x80;
        int mask2 = 0x20;
        int mask3 = 0x10;
        int mask4 = 0x08;
        int corner_case_mask = 0xC0; // mask for corner case string which exist independently like 10xxxxxx
        for (int i = 0; i < data.size(); i++)
        {
            if ((corner_case_mask & data[i]) == mask1)
                return false;
            int bytes{0};

            if ((mask1 & data[i]) == 0)
                continue;

            else if ((mask2 & data[i]) == 0)
                bytes = 1;
            else if ((mask3 & data[i]) == 0) 
                bytes = 2;
            else if ((mask4 & data[i]) == 0)
                bytes = 3;
            else
                return false;

            while (bytes--)
            {
                i++;
                if (i >= data.size() or ((corner_case_mask & data[i]) != mask1))
                {
                    return false;
                }
            }
        }
        return true;
    }
};