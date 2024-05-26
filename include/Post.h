#ifndef OOP_POST_H
#define OOP_POST_H

#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <limits>

enum class Property{Title, StackHeight}; // properties by which the list will be sorted accordingly
// Title will indicate to sort posts alphabetically by the title
// StackHeight will indicate to sort relevant posts, which contain more "pushed" information in a post

template <typename T, int size_arr_items>
class Post{ // similar to the stack implementation using arrays
protected:
    std::string author;
    char *title{};
    int bottom_index;
    T arr_content[size_arr_items];
public:
    Post();
    [[maybe_unused]] Post(std::string author, const char *title);
    Post(const Post<T, size_arr_items> &other_obj);
    Post<T, size_arr_items>& operator=(const Post<T, size_arr_items> &other_obj);
    virtual ~Post();

    void push(const T& obj);
    void pop();

    void setAuthor(const std::string &aut);
    void setTitle(const char *name);
    [[nodiscard]] const std::string &getAuthor() const;

    [[maybe_unused]] static bool sortCommentsCriteria(const Post<T, size_arr_items> &post1, const Post<T, size_arr_items> &post2, const Property &property);

    [[maybe_unused]] T bottom();
    Post<T, size_arr_items> operator+(const Post<T, size_arr_items> &x);
    friend std::ostream &operator<<(std::ostream &out, const Post<T, size_arr_items> &obj){
        obj.display(out);
        return out;
    }
    virtual void display(std::ostream& out) const;
    friend std::istream &operator>>(std::istream &in, Post<T, size_arr_items> &obj){
        obj.read(in);
        return in;
    }
    virtual void read(std::istream& in);
};

template<typename T, int size_arr_items>
[[maybe_unused]] bool Post<T, size_arr_items>::sortCommentsCriteria(const Post<T, size_arr_items> &post1, const Post<T, size_arr_items> &post2, const Property &property) {
    if(property == Property::StackHeight)
    {
        // descending order based on the height of each post
        return post1.bottom_index > post2.bottom_index;
    } else if(property == Property::Title)
    {
        // alphabetical order based on the title of each post
        return std::strcmp(post1.title, post2.title) < 0;
    }
    return false;
}

template<typename T, int size_arr_items>
const std::string &Post<T, size_arr_items>::getAuthor() const {
    return this->author;
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::setTitle(const char *name) {
    if(this->title != nullptr)
    {
        delete []this->title;
        this->title = nullptr;
    }
    this->title = new char[strlen(name)+1];
    strcpy(this->title, name);
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::setAuthor(const std::string &aut) {
    this->author = aut;
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::read(std::istream &in) {
    //in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"Enter the name of the author of this post:"<<std::endl;
    std::getline(in, this->author);
    char name[50];
    std::cout<<"Enter the title of this post, which contains at most 50 characters:"<<std::endl;
    in.get(name, 50); in.clear(); in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(this->title != nullptr)
    {
        delete []this->title;
        this->title = nullptr;
    }
    this->title = new char[strlen(name)+1];
    strcpy(this->title, name);
}

template<typename T, int size_arr_items>
Post<T, size_arr_items>::Post(): author("General") {
    this->title = new char[strlen("Undefined")+1];
    strcpy(this->title,"Undefined");
    bottom_index = -1;
    // when instantiating a post object, the array doesn't have any content, meaning the index that points to the bottom of the post is yet to be incremented
}

template<typename T, int size_arr_items>
[[maybe_unused]] Post<T, size_arr_items>::Post(std::string author, const char *title): author(std::move(author)), bottom_index(-1) { // NOLINT(*-pro-type-member-init)
    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
}

template<typename T, int size_arr_items>
Post<T, size_arr_items>::Post(const Post<T, size_arr_items> &other_obj): author(other_obj.author), bottom_index(other_obj.bottom_index) { // NOLINT(*-pro-type-member-init)
    this->title = new char[strlen(other_obj.title)+1];
    strcpy(this->title,other_obj.title);
    for(int i = 0; i <= other_obj.bottom_index; i++)
    {
        arr_content[i] = other_obj.arr_content[i];
    }
}

template<typename T, int size_arr_items>
Post<T, size_arr_items> &Post<T, size_arr_items>::operator=(const Post<T, size_arr_items> &other_obj) {
    if(this != &other_obj)
    {
        if(this->title != nullptr)
        {
            delete []this->title;
            this->title = nullptr;
        }
        this->title = new char[strlen(other_obj.title)+1];
        strcpy(this->title, other_obj.title);
        this->author = other_obj.author;
        for(int i = 0; i <= other_obj.bottom_index; i++)
        {
            arr_content[i] = other_obj.arr_content[i];
        }
        this->bottom_index = other_obj.bottom_index;
        // when assigning a smaller stack to a larger stack, the bottom_index of the larger stack won't surpass the size of the smaller stack, meaning previous elements in the larger stack will be ignored and most likely overwritten
    }
    return *this;
}

template<typename T, int size_arr_items>
Post<T, size_arr_items>::~Post() {
    if(this->title != nullptr)
    {
        delete []this->title;
        this->title = nullptr;
    }
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::push(const T &obj) {
    if(bottom_index < size_arr_items-1) // check upper bound
    {
        ++bottom_index;
        arr_content[bottom_index] = obj;
    }
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::pop() {
    if(bottom_index >= 0) // check lower bound
    {
        bottom_index--;
    }
}

template<typename T, int size_arr_items>
[[maybe_unused]] T Post<T, size_arr_items>::bottom() {
    if(bottom_index < 0)
    {
        return;
    }
    return arr_content[bottom_index];
}

template<typename T, int size_arr_items>
Post<T, size_arr_items> Post<T, size_arr_items>::operator+(const Post<T, size_arr_items> &x) {
    Post<T, size_arr_items> aux = new Post();
    // if the sum of no items included in both stacks exceed the maximum size of size_arr_items, they won't be pushed onto the final aux stack
    for(int i = 0; i <= this->bottom_index; i++)
    {
        if(aux.bottom_index < size_arr_items-1)
        {
            aux.bottom_index++;
            aux.arr_content[i] = this->arr_content[i];
        }
    }
    for(int i = 0; i <= x.bottom_index; i++)
    {
        if(aux.bottom_index < size_arr_items-1)
        {
            aux.bottom_index++;
            aux.arr_content[i] = x.arr_content[i];
        }
    }
    return aux;
}

template<typename T, int size_arr_items>
void Post<T, size_arr_items>::display(std::ostream &out) const {
    if(this->author != "General")
    {
        out<<std::endl<<this->author<<"'s post:"<<std::endl;
        out<<"\tPost title: "<<this->title<<std::endl;
    }
    out<<"\tPost content: "<<std::endl;
    for(int i = 0; i <= this->bottom_index; i++)
    {
        out<<arr_content[i]<<std::endl;
    }
    out<<std::endl;
}

#endif //OOP_POST_H