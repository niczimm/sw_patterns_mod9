#include <string>
#include "Element.H"    
#include "Node.H"
#include <iostream>

// Chain of Responsibility Pattern - Handler Interface
class Handler
{
public:
    virtual void setNextHandler(Handler* handler) = 0;
    virtual bool handleRequest(const std::string& request) = 0;
    virtual void setHandlerMessage(const std::string& message) = 0;
};

// Chain of Responsibility Pattern - Concrete Handler
class HandlerElement : public Element_Impl, public Handler
{
private:
    HandlerElement* successor;
    std::string handlerMessage;

public:
    HandlerElement(const std::string& name, dom::Document* ownerDoc): Element_Impl(name, ownerDoc){}

    void setHandlerMessage(const std::string& message)
    {
        handlerMessage = message;
    }

    void setNextHandler(Handler* handler) override
    {
        successor = dynamic_cast<HandlerElement*>(handler);
    }

    bool handleRequest(const std::string& request)
    {
        setNextHandler(dynamic_cast<HandlerElement*>(this->getParentNode())); // Set next successor
        if (handlerMessage == request) {
            std::cout << "Handled: " << request << " @ <" << getTagName() << ">\n";
            return true;
        }
        else if (successor) {
            return successor->handleRequest(request);
        }
        return false;
    }

    // bool handleRequest(const std::string& message)
    // {
    //     Element_Impl* current = this;

    //     while (current != nullptr)
    //     {
    //         if (Handler* h = dynamic_cast<Handler*>(current)) {
    //             if (h->handleRequest(message))
    //                 std::cout << "Handled: " << message << " from: " << getTagName() << "\n";
    //                 return true;
    //         }
    //         current = dynamic_cast<Element_Impl*>(current->getParentNode()); // Set next successor
    //     }

    //     return false;
    // }
};