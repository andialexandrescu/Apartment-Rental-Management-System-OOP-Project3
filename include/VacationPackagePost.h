#ifndef OOP_VACATIONPACKAGEPOST_H
#define OOP_VACATIONPACKAGEPOST_H

#include <iostream>
#include "Post.h"
#include "ApartmentListingPost.h"
#include "PackageType.h"
#include <map>
#include <vector>
#include <typeinfo>

template <typename T, int size_arr_items>
class VacationPackagePost: public Post<T, size_arr_items>{
private:
    std::map<PackageType, std::vector<Post<T, size_arr_items> *>> map_package_posts;
public:
    VacationPackagePost() = default;
    /*VacationPackagePost(const VacationPackagePost &other_obj);
    VacationPackagePost<T, size_arr_items> &operator=(const VacationPackagePost &other_obj);*/
    ~VacationPackagePost() override;

    [[maybe_unused]] void addPost(const PackageType &pkg, Post<T, size_arr_items> *obj); // adding a post to the vector based on the package it corresponds to

    void read(std::istream& in) override;
    void display(std::ostream& out) const override;
};

template<typename T, int size_arr_items>
void VacationPackagePost<T, size_arr_items>::display(std::ostream &out) const {
    out<<this->getAuthor()<<"'s vacation package listing:"<<std::endl;
    Post<T, size_arr_items>::display(out);
    out<<"The vacation deal includes the following type of packages available and their corresponding apartment listings posts:"<<std::endl;
    for(const auto& pair : this->map_package_posts)
    {
        out<<std::endl<<"\tPackage type:"<<std::endl;
        out<<pair.first<<std::endl;
        out<<std::endl<<"\tApartment listings contained in "<<pair.first<<" are:"<<std::endl;
        // RTTI typeid operator: every class has a typical typeinfo object associated with it
        // typeid(ptr) yield the object the ptr is pointing to
        for(Post<T, size_arr_items>* ptr_post : pair.second)
        {
            if(typeid(*ptr_post) == typeid(ApartmentListingPost<T, size_arr_items>))
            {
                /*auto* ptr_apt_post = dynamic_cast<ApartmentListingPost<T, size_arr_items>*>(ptr_post);
                if(ptr_apt_post)
                {
                    ptr_apt_post->display(out);
                }*/
                out<<"Available accomodations:"<<std::endl;
                ptr_post->display(out);
            } else
            {
                out<<"Tours and resturants section:"<<std::endl;
                ptr_post->display(out);
            }
        }
    }
}

template<typename T, int size_arr_items>
void VacationPackagePost<T, size_arr_items>::read(std::istream &in) {
    std::cout<<"Enter all details that are relevant for a vacation package post"<<std::endl;
    Post<T, size_arr_items>::read(in);
    if(typeid(T) == typeid(std::string))
    {
        int no_lines;
        std::cout<<"Enter the amount of lines the reply post will contain"<<std::endl;
        std::cin>>no_lines; std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(no_lines > 0)
        {
            std::string text;
            std::cout<<"Enter the current post line"<<std::endl;
            std::getline(std::cin, text);
            this->push(text);
            no_lines--;
        }
    }
}

template<typename T, int size_arr_items>
[[maybe_unused]] void VacationPackagePost<T, size_arr_items>::addPost(const PackageType &pkg, Post<T, size_arr_items> *obj) {
    typename std::map<PackageType, std::vector<Post<T, size_arr_items> *>>::iterator it_pair;
    it_pair = map_package_posts.find(pkg);
    if(it_pair != map_package_posts.end()) // it is found
    {
        it_pair->second.push_back(obj);
    } else // it means the key is not yet part of the dictionary
    {
        std::vector<Post<T, size_arr_items>*> aux_inner_posts;
        aux_inner_posts.push_back(obj);
        map_package_posts.insert(std::make_pair(pkg, aux_inner_posts));
    }
}

template<typename T, int size_arr_items>
VacationPackagePost<T, size_arr_items>::~VacationPackagePost() {
    if(!this->map_package_posts.empty())
    {
        for(auto& pair : this->map_package_posts)
        {
            /*for(Post<T, size_arr_items>* post : pair.second)
            {
                delete post; // delete each Post instance in the vector
            }*/
            pair.second.clear(); // clear each vector
        }
        this->map_package_posts.clear();
    }
}

/*template<typename T, int size_arr_items>
VacationPackagePost<T, size_arr_items> &VacationPackagePost<T, size_arr_items>::operator=(const VacationPackagePost &other_obj) {
    if(this != &other_obj)
    {
        Post<T, size_arr_items>::operator=(other_obj);
        this->apt_pair = other_obj.apt_pair;
        if(!this->map_package_posts.empty())
        {
            for(auto& pair : this->map_package_posts)
            {
                for(Post<T, size_arr_items>* post : pair.second)
                {
                    delete post; // delete each Post instance in the vector
                }
                pair.second.clear(); // clear each vector
            }
            this->map_package_posts.clear();
        }
        for(const auto& pair : other_obj.map_package_posts)
        {
            std::vector<Post<T, size_arr_items>*> aux_inner_posts;
            for(Post<T, size_arr_items>* ptr_post : pair.second)
            {
                aux_inner_posts.push_back(new Post<T, size_arr_items>(*ptr_post)); // deep copy for each Post instance
            }
            map_package_posts[pair.first] = aux_inner_posts;
        }
    }
    return *this;
}

template<typename T, int size_arr_items>
VacationPackagePost<T, size_arr_items>::VacationPackagePost(const VacationPackagePost &other_obj): Post<T, size_arr_items>(other_obj) {
    for(const auto& pair : other_obj.map_package_posts)
    {
        std::vector<Post<T, size_arr_items>*> aux_inner_posts;
        for(Post<T, size_arr_items>* ptr_post : pair.second)
        {
            if(ptr_post != nullptr)
            {
                aux_inner_posts.push_back(new Post<T, size_arr_items>(*ptr_post)); // deep copy each Post instance
            }
        }
        map_package_posts[pair.first] = aux_inner_posts;
    }
}

template<typename T, int size_arr_items>
VacationPackagePost<T, size_arr_items>::VacationPackagePost(): Post<T, size_arr_items>() {
    // the default constructor for map is implicitly called
}*/

#endif //OOP_VACATIONPACKAGEPOST_H