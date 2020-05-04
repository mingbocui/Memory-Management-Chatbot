#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot& other){
        _image = other._image;
        _currentNode = other._currentNode;
        _rootNode = other._rootNode;
        _chatLogic = other._chatLogic;
    }

    ChatBot(ChatBot&& other){
        _image = other._image;
        _currentNode = other._currentNode;
        _rootNode = other._rootNode;
        _chatLogic = other._chatLogic;
    }

    ChatBot& operator=(const ChatBot& other){
        if(&other != this){
            _image = other._image;
            _currentNode = other._currentNode;
            _rootNode = other._rootNode;
            _chatLogic = other._chatLogic;
        }
        return *this;
    }

    ChatBot& operator=(ChatBot&& other){
        if(&other != this){
            _image = other._image;
            other._image = nullptr;
            _currentNode = other._currentNode;
            other._currentNode = nullptr;
            _rootNode = other._rootNode;
            other._rootNode = nullptr;
            _chatLogic = other._chatLogic;
            other._chatLogic = nullptr;

        }
        return *this;
    }

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */