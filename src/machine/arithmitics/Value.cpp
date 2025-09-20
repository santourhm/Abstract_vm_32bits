#include "Value.hpp"
#include <iostream>
#include <cmath>

#include "Op_Results.hpp"


Value::Value() : data(std::monostate{})
{
    this->type = TypeTag::UNDEFINED;
    
}

Value::Value(int32_t val)
{
    this->type = TypeTag::INTEGER;
    this->data = val;
}

Value::Value(float val)
{
    this->type = TypeTag::FLOAT;
    this->data = val;
}


Value::Value(uint32_t val,TypeTag t)
{
    this->type = t;
    this->data = val;
}

Value::Value(std::string val)
{
    this->type = TypeTag::STRING;
    this->data = val;
}

TypeTag Value::getType() const
{
    return this->type;
}

Value& Value::operator++()
{
    switch (type) 
    {
        case TypeTag::INTEGER: 
        {
            int32_t& val = std::get<int32_t>(data);
            ++val;
            break;
        }
        case TypeTag::FLOAT: 
        {
            float& val = std::get<float>(data);
            ++val;
            break;
        }
        case TypeTag::ADDRESS: 
        {
            uint32_t& val = std::get<uint32_t>(data);
            ++val;
            break;
        }
        default:
            throw std::runtime_error("Increment not supported for this type");
    }

    return *this;
}

Value& Value::operator--()
{

    switch (type) 
    {
        case TypeTag::INTEGER: 
        {
            int32_t& val = std::get<int32_t>(data);
            --val;
            break;
        }
        case TypeTag::FLOAT: 
        {
            float& val = std::get<float>(data);
            --val;
            break;
        }
        case TypeTag::ADDRESS: 
        {
            uint32_t& val = std::get<uint32_t>(data);
            --val;
            break;
        }
        default:
            throw std::runtime_error("Increment not supported for this type");
    }

    return *this;
}

Value Value::operator++(int)
{
    Value temp = *this;  
    ++(*this);           
    return temp;         
}

Value Value::operator--(int)
{
    Value temp = *this;  
    --(*this);           
    return temp;         
}

template<typename IntOp, typename FloatOp, typename AddrOp>
static Op_Results arithmeticOp(const Value& lhs, const Value& rhs,
                               IntOp intOp,
                               FloatOp floatOp, AddrOp addrOp)
{
    Op_Results result;

    if (lhs.getType() == TypeTag::UNDEFINED || rhs.getType() == TypeTag::UNDEFINED) 
    {
        throw std::runtime_error(" : Cannot operate on UNDEFINED value");
    }

   if (lhs.getType() == TypeTag::ADDRESS || lhs.getType() == TypeTag::NULL_ADDR ||
        rhs.getType() == TypeTag::ADDRESS || rhs.getType() == TypeTag::NULL_ADDR)
    {
        uint32_t lhs_val = 0;
        uint32_t rhs_val = 0;


        if (lhs.getType() == TypeTag::ADDRESS) lhs_val = lhs.getAddr();
        else if (lhs.getType() == TypeTag::NULL_ADDR) lhs_val = 0;
        else if (lhs.getType() == TypeTag::INTEGER) lhs_val = static_cast<uint32_t>(lhs.getInt());
        else throw std::runtime_error(" : Unsupported lhs type for Address/Null arithmetic");

        if (rhs.getType() == TypeTag::ADDRESS) rhs_val = rhs.getAddr();
        else if (rhs.getType() == TypeTag::NULL_ADDR) rhs_val = 0;
        else if (rhs.getType() == TypeTag::INTEGER) rhs_val = static_cast<uint32_t>(rhs.getInt());
        else throw std::runtime_error(" : Unsupported rhs type for Address/Null arithmetic");

        uint32_t aRes = addrOp(lhs_val, rhs_val);

        result.val = Value(aRes, TypeTag::ADDRESS); 

        result.cc.OV = 0;
        result.cc.EQ = (aRes == 0);
        result.cc.NE = (aRes != 0);
        result.cc.GT = (aRes > 0);
        result.cc.LT = false;
        result.cc.GE = true;
        result.cc.LE = (aRes == 0);
        result.cc.NG = (aRes < 0);
    }
    // Case 2: Float operation
    else if (lhs.getType() == TypeTag::FLOAT || rhs.getType() == TypeTag::FLOAT)
    {
        float lhs_f = (lhs.getType() == TypeTag::FLOAT) ? lhs.getFloat() : static_cast<float>(lhs.getInt());
        float rhs_f = (rhs.getType() == TypeTag::FLOAT) ? rhs.getFloat() : static_cast<float>(rhs.getInt());

        float fRes = floatOp(lhs_f, rhs_f);
        result.val = Value(fRes);

        result.cc.OV = std::isinf(fRes) ? 1 : 0;
        result.cc.EQ = (fRes == 0.0f);
        result.cc.NE = (fRes != 0.0f);
        result.cc.GT = (fRes > 0.0f);
        result.cc.LT = (fRes < 0.0f);
        result.cc.GE = (fRes >= 0.0f);
        result.cc.LE = (fRes <= 0.0f);
        result.cc.NG = (fRes < 0);

    }

    else if (lhs.getType() == TypeTag::INTEGER && rhs.getType() == TypeTag::INTEGER)
    {
        int32_t lhs_i = lhs.getInt();
        int32_t rhs_i = rhs.getInt();
        int32_t iRes = intOp(lhs_i, rhs_i);
        result.val = Value(iRes);

        result.cc.OV = 0; 

        result.cc.EQ = (iRes == 0);
        result.cc.NE = (iRes != 0);
        result.cc.GT = (iRes > 0);
        result.cc.LT = (iRes < 0);
        result.cc.GE = (iRes >= 0);
        result.cc.LE = (iRes <= 0);
        result.cc.NG = (iRes < 0);

    }
    else {
        throw std::runtime_error(" : Unsupported types for arithmetic operation");
    }

    return result;
}



Op_Results Value::operator+(const Value& rhs) const {
    Op_Results result = arithmeticOp(*this, rhs,
        [](int32_t a, int32_t b){ return a + b; },
        [](float a, float b){ return a + b; },[](uint32_t a, uint32_t b){ return a + b; });

    if (result.val.getType() == TypeTag::INTEGER) {
        int32_t lhs_i = this->getInt();
        int32_t rhs_i = rhs.getInt();
        int32_t res_i = result.val.getInt();
        if ((lhs_i > 0 && rhs_i > 0 && res_i < 0) || (lhs_i < 0 && rhs_i < 0 && res_i > 0)) {
            result.cc.OV = 1;
        }
    }
    return result;
}

Op_Results Value::operator-(const Value& rhs) const {
    return arithmeticOp(*this, rhs,
        [](int32_t a, int32_t b){ return a - b; },
        [](float a, float b){ return a - b; },[](uint32_t a, uint32_t b){ return a - b; });
}

Op_Results Value::operator*(const Value& rhs) const {
    return arithmeticOp(*this, rhs,
        [](int32_t a, int32_t b){ return a * b; },
        [](float a, float b){ return a * b; },[](uint32_t a, uint32_t b){ return a*b; });
}

Op_Results Value::operator/(const Value& rhs) const {
    return arithmeticOp(*this, rhs,
        [](int32_t a, int32_t b){
            if (b == 0) throw std::runtime_error(" : Division by zero");
            return a / b;
        },
        [](float a, float b){
            if (b == 0.0f) throw std::runtime_error(" : Division by zero");
            return a / b;
        },
        [](uint32_t a, uint32_t b){ 
            if (b == 0x0) throw std::runtime_error(" : Division by zero");
            return a/b; });
}

Op_Results Value::operator%(const Value& rhs) const {
    return arithmeticOp(*this, rhs,
        [](int32_t a, int32_t b){
            if (b == 0) throw std::runtime_error(" : Modulo by zero");
            return a % b;
        },
       
        [](float, float) -> float { 
            throw std::runtime_error(" : Modulo not defined for floats");
        }
        ,[](uint32_t a, uint32_t b){ return a%b; });
}



CC Value::operator<(const Value& rhs) const
{
    Op_Results reslts = rhs - *this;
    return reslts.cc;
}

CC Value::operator<=(const Value& rhs) const
{
    Op_Results reslts = rhs - *this;
    return reslts.cc;
}

CC Value::operator>(const Value& rhs) const
{
    Op_Results reslts = rhs - *this;
    return reslts.cc;
}

CC Value::operator>=(const Value& rhs) const
{
    Op_Results reslts = rhs - *this;
    return reslts.cc;
}


CC Value::operator==(const Value& rhs) const
{
    Op_Results reslts = rhs - *this;
    return reslts.cc;
}


int32_t Value::getInt() const { return std::get<int32_t>(data); }

float Value::getFloat() const { return std::get<float>(data); }

uint32_t Value::getAddr() const 
{ 
    return std::get<uint32_t>(data); 
}

std::string Value::getStr() const { return std::get<std::string>(data); }

std::string Value::get_str_type()
{
      switch (this->type)
      {
            case TypeTag::ADDRESS:
                  
                  return std::string("ADDRESS");

            case TypeTag::UNDEFINED:
                  
                  return std::string("UNDEFINED");
            case TypeTag::NULL_ADDR:
                  
                  return std::string("NULL_ADDR");

            default:
                  break;
      }
      return std::string("UKNOWN");
}




std::ostream& operator<<(std::ostream& os, const Value& val) 
{
    switch (val.getType()) {
        case TypeTag::STRING:
            os << val.getStr();
            break;
        case TypeTag::ADDRESS:
            os << "0x" << std::hex << val.getAddr() << std::dec; 
            break;
        case TypeTag::INTEGER:
            os << val.getInt();
            break;
        case TypeTag::FLOAT:
            os << val.getFloat();
            break;
        case TypeTag::NULL_ADDR:
            os << "null";
            break;
        default:
            os << "UNDEFINED";
            break;
    }
    return os;
}
