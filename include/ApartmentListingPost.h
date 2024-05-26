#ifndef OOP_APARTMENTLISTINGPOST_H
#define OOP_APARTMENTLISTINGPOST_H

#include "Post.h"
#include "User.h"
#include "SearchEngine.h"
#include "ApartmentLayout.h"
#include <iostream>
#include <list>
#include <utility>
#include <limits>

// general comment: project-2 had memory leaks solved with shared pointers because i didn't properly understand when to delete pointers and how to exactly manage deep copy instructions, now i'm working on project-3 and i will not be solving these past issues since it will take a lot of time, but good to know why those shared pointers were used and how i could've prevented the usage

template <typename T, int size_arr_items>
class ApartmentListingPost: public Post<T, size_arr_items>{
private:
    std::pair<std::shared_ptr<Apartment>, std::shared_ptr<ApartmentLayout>> apt_pair;
    // l_comments will represent a list containing comments left by tenants who spent their stay at a certain host's apartment
    std::list<std::shared_ptr<Post<T, size_arr_items>>> l_comments; // doubly linked list containing pointers to Post instances which are meant to showcase the imbrication of multiple posts within another post
    // the explicit implementation of a list containing pointers to instances of the base class is meant to replicate how the current stack is able to retain other stacks "containing less info" (since posts made by tenants exist both independently and inside a larger post created by a host) within by linking them together
    // the reason behind using list is that there's constant time insert and erase operations, since i will need to move inappropriate comments made by tenants to the end of l_comments
public:
    ApartmentListingPost();
    [[maybe_unused]] ApartmentListingPost(const std::string &author, const char *title, Apartment *apt, ApartmentLayout *apt_layout);
    [[maybe_unused]] ApartmentListingPost(const ApartmentListingPost &other_obj);
    ApartmentListingPost<T, size_arr_items>& operator=(const ApartmentListingPost &other_obj);
    ~ApartmentListingPost() override;

    void setApartmentPair(const std::shared_ptr<Apartment> &apt, const std::shared_ptr<ApartmentLayout> &apt_layout);
    const std::list<std::shared_ptr<Post<T, size_arr_items>>> &getListComments() const;

    // l_comments helper methods
    [[maybe_unused]] void addPost(Post<T, size_arr_items> *obj);
    void moveCommentsFront(const std::vector<int> &arr); // decided to move posts to the front since it provides the usage of modifier functions within list, which are not available for vector (list, vector and deque are similar, yet vector is more restricted and cannot insert explicitly items to the front)
    void addHostReplies();

    void read(std::istream& in) override;
    void readFromPost(std::istream& in);
    void display(std::ostream& out) const override;
};

template<typename T, int size_arr_items>
ApartmentListingPost<T, size_arr_items>::~ApartmentListingPost() {
    this->apt_pair.first.reset();
    this->apt_pair.second.reset();
    if(!this->l_comments.empty())
    {
        for(auto &ptr_post : this->l_comments)
        {
            ptr_post.reset();
        }
        this->l_comments.clear();
    }
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::readFromPost(std::istream &in) {
    Post<T, size_arr_items>::read(in);
}

template<typename T, int size_arr_items>
const std::list<std::shared_ptr<Post<T, size_arr_items>>> &ApartmentListingPost<T, size_arr_items>::getListComments() const {
    return this->l_comments;
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::setApartmentPair(const std::shared_ptr<Apartment> &apt, const std::shared_ptr<ApartmentLayout> &apt_layout) {
    this->apt_pair.first = apt;
    this->apt_pair.second = apt_layout;
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::display(std::ostream &out) const {
    out<<this->getAuthor()<<"'s apartment listing:"<<std::endl;
    Post<T, size_arr_items>::display(out);
    out<<"The apartment's specifications including a short description followed by the layout:"<<std::endl;
    out<<std::endl<<"\tApartment section:"<<std::endl;
    out<<*(apt_pair.first)<<std::endl;
    out<<std::endl<<"\tApartment layout section:"<<std::endl;
    out<<*(apt_pair.second)<<std::endl;
    out<<std::endl<<"\tFloor plan section:"<<std::endl<<std::endl;
    std::shared_ptr<ApartmentLayout> apt_layout = apt_pair.second;
    apt_layout->displayFloorPlan();
    out<<std::endl<<"Comment section:"<<std::endl;
    for(const auto &ptr_post : this->l_comments) // reference to pointer in order to be able to access the Post instances
    {
        out<<*ptr_post<<std::endl; // dereferencing the pointers
    }
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::addHostReplies() {
    unsigned long long n;
    std::cout<<"Enter the n-th post that you want to reply to: ";
    std::cin>>n; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /*Post<T, size_arr_items> *ptr_post;
    ptr_post = new Post<T, size_arr_items>; // init constructor*/
    auto ptr_post = std::make_shared<Post<T, size_arr_items>>(); // dynamically allocate memory for the new Post object using a shared pointer
    std::cout<<"The reply post will be generated according to the author name provided, titled <Reply made by host to <displayed name>'s post>"<<std::endl;
    ptr_post->setAuthor(this->getAuthor());
    //typename std::list<Post<T, size_arr_items>*>::iterator it = l_comments.begin();
    auto it = l_comments.begin();
    if(n < l_comments.size())
    {
        std::advance(it, n);
        //Post<std::string, size_arr_items>* post_str = dynamic_cast<Post<std::string, size_arr_items>*>(ptr_post);
        if(typeid(T) == typeid(std::string))
        {
            std::string title = "Reply made by host to " + (*it)->getAuthor() + "'s post"; // dereferencing the iterator
            const char* title_cstr = title.c_str();
            ptr_post->setTitle(title_cstr);
            // const char * implemented using c_str() method from std::string
        } else
        {
            std::cout<<"Error: Post type is not a comment, content is not string"<<std::endl;
        }
    }
    int no_lines;
    std::cout<<"Enter the amount of lines the reply post will contain"<<std::endl;
    std::cin>>no_lines; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(no_lines > 0)
    {
        std::string text;
        std::cout<<"Enter the current post line"<<std::endl;
        std::getline(std::cin, text);
        ptr_post->push(text);
        no_lines--;
    }
    ++it; // the insert operation occurs before the iterator, therefore it should point to the following post, in order to insert the reply before the next post in l_comments
    l_comments.insert(it, std::move(ptr_post)); // release the pointer before inserting into the list
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::read(std::istream &in) {
    Post<T, size_arr_items>::read(in);
    std::string apt_id;
    std::cout<<"Enter the apartment ID:"<<std::endl;
    std::getline(in, apt_id);
    bool apt_found = false;
    std::shared_ptr<Apartment> ptr_apt;
    std::vector<Apartment> apts = query.getApts();
    for(const auto& apt : apts)
    {
        if(apt.getApartmentID() == apt_id)
        {
            if(typeid(T)==typeid(std::string))
            {
                this->push("Listing of apartment " + apt_id + ":");
            }
            //ptr_apt = const_cast<Apartment *>(&apt); // l_apts from SearchEngine contain actual instances meaning Apartment * const must be converted to Apartment *
            ptr_apt = std::make_shared<Apartment>(apt);
            apt_found = true;
            break;
        }
    }
    if(!apt_found)
    {
        std::cout << "The apartment id wasn't found" << std::endl;
    }
    if(ptr_apt != nullptr)
    {
        std::shared_ptr<ApartmentLayout> ptr_layout = std::make_shared<ApartmentLayout>(); // not really interested for the time being when it comes to ApartmentLayout, because the usual format in which these things will work most of the time is that an instance of ApartmentListingPost will use readFromPost then use the setter for the apartment pair, instead of the read function via std::cin
        this->setApartmentPair(ptr_apt, ptr_layout); // don't know what happens if the ptr_apt remains nullptr
    }
}

template<typename T, int size_arr_items>
void ApartmentListingPost<T, size_arr_items>::moveCommentsFront(const std::vector<int> &arr) {
    for(unsigned long long pos : arr) // arr[] will only contain the indexes of comments that need to be moved to the front of l_comments, the comment section
    {
        if(pos < l_comments.size())
        {
            auto it = l_comments.begin(); // in order to access the element in the list based on the index provided within the container, an iterator is needed
            std::advance(it, pos); // avoid a while loop by moving the iterator forward by a specified position
            auto ptr_post = *it; // the post should actually be pointed at by the iterator therefore it must be dereferenced
            l_comments.erase(it);
            l_comments.push_front(ptr_post);
        }
    }
}

template<typename T, int size_arr_items>
ApartmentListingPost<T, size_arr_items>::ApartmentListingPost(): Post<T, size_arr_items>() {
    // the no parameters init constructor
    apt_pair.first = std::make_shared<Apartment>();
    apt_pair.second = std::make_shared<ApartmentLayout>();
    if(!this->l_comments.empty())
    {
        for(auto &ptr_post : this->l_comments)
        {
            ptr_post.reset();
        }
        this->l_comments.clear();
    }
}

template<typename T, int size_arr_items>
[[maybe_unused]] ApartmentListingPost<T, size_arr_items>::ApartmentListingPost(const std::string &author, const char *title, Apartment *apt, ApartmentLayout *apt_layout): Post<T, size_arr_items>(author, title), apt_pair(apt, apt_layout) {}


template<typename T, int size_arr_items>
ApartmentListingPost<T, size_arr_items> &ApartmentListingPost<T, size_arr_items>::operator=(const ApartmentListingPost &other_obj){
    if(this != &other_obj)
    {
        Post<T, size_arr_items>::operator=(other_obj);
        apt_pair.first = std::make_shared<Apartment>(*other_obj.apt_pair.first);
        apt_pair.second = std::make_shared<ApartmentLayout>(*other_obj.apt_pair.second);
        if(!this->l_comments.empty())
        {
            for(auto &ptr_post : this->l_comments)
            {
                ptr_post.reset();
            }
            this->l_comments.clear();
        }
        // deep copy since it prevents unintended sharing of the same object between multiple ApartmentListingPost instances
        for(const auto& ptr_post : other_obj.l_comments) // reference to pointer in order to be able to access the Post instances
        {
            l_comments.push_back(std::make_shared<Post<T, size_arr_items>>(*ptr_post));
        }
    }
    return *this;
}

template<typename T, int size_arr_items>
[[maybe_unused]] ApartmentListingPost<T, size_arr_items>::ApartmentListingPost(const ApartmentListingPost &other_obj): Post<T, size_arr_items>(other_obj) {
    // a new object is created by using the copy constructor of User which takes the dereferenced pointer to another object of that class as a parameter
    std::cout<<"Copy constructor used"<<std::endl;
    apt_pair.first = std::make_shared<Apartment>(*other_obj.apt_pair.first);
    apt_pair.second = std::make_shared<ApartmentLayout>(*other_obj.apt_pair.second);
    // since l_comments contains pointers to Post objects we must deep copy the items contained in the other object's list of comments
    // wrong: this->l_comments = other_obj.l_comments; it only copies the pointers, meaning that in the current case (non-const pointer pointing to non-const data) a shallow copy will be created
    for (const auto& ptr_post : other_obj.l_comments)
    {
        l_comments.push_back(std::make_shared<Post<T, size_arr_items>>(*ptr_post));
    }
}

template<typename T, int size_arr_items>
[[maybe_unused]] void ApartmentListingPost<T, size_arr_items>::addPost(Post<T, size_arr_items> *obj)
{
    this->l_comments.push_back(std::make_shared<Post<T, size_arr_items>>(*obj));
}

#endif //OOP_APARTMENTLISTINGPOST_H