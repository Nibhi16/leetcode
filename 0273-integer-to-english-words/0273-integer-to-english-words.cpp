class Solution {
public:
    vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                              "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                              "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return below20[num] + " ";
        else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
        else return below20[num / 100] + " Hundred " + helper(num % 100);
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string result = "";

        int billion = num / 1000000000;
        int million = (num / 1000000) % 1000;
        int thousand = (num / 1000) % 1000;
        int rest = num % 1000;

        if (billion) result += helper(billion) + "Billion ";
        if (million) result += helper(million) + "Million ";
        if (thousand) result += helper(thousand) + "Thousand ";
        if (rest) result += helper(rest);

        // Trim extra spaces
        while (result.back() == ' ') result.pop_back();
        return result;
    }
};
