package com.fastcampus.ch4;

import jakarta.persistence.*;

@Entity
public class Member {
    @Id
    @Column(name="member_id")
    private Long id;
    private String password;
    private String name;
    private String email;

    @OneToOne(mappedBy="member") // FK 안생김
//    @JoinColumn(name="cart_id") // 양방향일때는 필요가 없음
    private Cart cart;

    @Override
    public String toString() {
        return "Member{" +
                "id=" + id +
                ", password='" + password + '\'' +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", cart=" + cart +
                '}';
    }

    public Cart getCart() {
        return cart;
    }

    public void setCart(Cart cart) {
        this.cart = cart;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
