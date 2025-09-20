#ifndef VALUE_HPP
#define VALUE_HPP

#include <cstdint>
#include <string>
#include <variant>
#include <ostream>   
#include <iomanip> 

struct Op_Results;
struct CC;

enum class TypeTag {
    UNDEFINED,
    INTEGER,
    FLOAT,
    ADDRESS,
    STRING,
    NULL_ADDR
};

class Value
{
    private:
        TypeTag type;
        std::variant<std::monostate,int32_t, float, uint32_t, std::string> data;

    public:
        Value();

        explicit Value(int32_t val);
        explicit Value(float val);
        explicit Value(uint32_t val, TypeTag t = TypeTag::ADDRESS) ;
        explicit Value(std::string val);

        static Value NullAddr() 
        {
            Value v;
            v.type = TypeTag::NULL_ADDR;
            v.data = std::monostate{}; 
            return v;
        }

        bool isNull() const 
        {
            return type == TypeTag::NULL_ADDR;
        }

        ~Value() = default;

        TypeTag getType() const;
        std::variant<int32_t, float, uint32_t, std::string> getDate() const;

        Op_Results operator+(const Value& rhs) const;
        Op_Results operator-(const Value& rhs) const;
        Op_Results operator/(const Value& rhs) const;
        Op_Results operator%(const Value& rhs) const;
        Op_Results operator*(const Value& rhs) const;
        
        Value& operator++();
        Value& operator--();
        Value operator++(int);
        Value operator--(int);

        CC operator<(const Value& rhs) const;
        CC operator<=(const Value& rhs) const;
        CC operator>(const Value& rhs) const;
        CC operator>=(const Value& rhs) const;
        CC operator==(const Value& rhs) const;

        int32_t getInt() const;
        float getFloat() const;
        uint32_t getAddr() const;
        std::string getStr() const;
        std::string get_str_type();
        
};


std::ostream& operator<<(std::ostream& os, const Value& val) ;

#endif