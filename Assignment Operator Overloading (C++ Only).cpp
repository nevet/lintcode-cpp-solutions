class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (this == &object) return *this;
        if (this->m_pData) {
            delete[] this->m_pData;
            this->m_pData = NULL;
        }
        if (object.m_pData) {
            this->m_pData = new char[strlen(object.m_pData)];
            strcpy(this->m_pData, object.m_pData);
        }
        
        return *this;
    }
};