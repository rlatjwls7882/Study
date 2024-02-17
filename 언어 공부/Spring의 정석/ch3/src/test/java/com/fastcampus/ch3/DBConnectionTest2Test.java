package com.fastcampus.ch3;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Date;

import static org.junit.Assert.assertTrue;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = {"file:src/main/webapp/WEB-INF/spring/**/root-context.xml"})
public class DBConnectionTest2Test {
    @Autowired
    DataSource ds;

    @Test
    public void insertUserTest() throws Exception {
        User user = new User("asdf2", "1234", "abc", "aaaa@aaa.com", new Date(), "fb", new Date());
        deleteAll();
        int rowCnt = insertUser(user);

        assertTrue(rowCnt==1);
    }

    @Test
    public void selectUserTest() throws Exception {
        User user = new User("asdf2", "1234", "abc", "aaaa@aaa.com", new Date(), "fb", new Date());
        deleteAll();
        int rowCnt = insertUser(user);
        User user2 = selectUser("asdf2");

        assertTrue(user2.getId().equals("asdf2"));
    }

    @Test
    public void deleteUserTest() throws Exception {
        deleteAll();
        int rowCnt = deleteUser("asdf");
        assertTrue(rowCnt==0);

        User user = new User("asdf2", "1234", "abc", "aaaa@aaa.com", new Date(), "fb", new Date());
        rowCnt = insertUser(user);
        assertTrue(rowCnt==1);

        rowCnt = deleteUser(user.getId());
        assertTrue(rowCnt==1);

        assertTrue(selectUser(user.getId())==null);
    }

    @Test
    public void updateUserTest() throws Exception {
        User user = new User("asdf2", "1234", "abc", "aaaa@aaa.com", new Date(), "fb", new Date());
        insertUser(user);

        int cnt = updateUser(user);
        assertTrue(cnt==1);
        System.out.println("cnt = " + cnt);
    }

    // 매개변수로 받은 사용자 정보로 user_info 테이블을 update하는 메서드
    public int updateUser(User user) throws Exception {
        Connection conn = ds.getConnection();

        String sql = "update user_info set id=?, pwd=?, name=?, email=?, birth=?, sns=?, reg_date=? where id=?";
        PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
        pstat.setString(1, user.getId());
        pstat.setString(2, user.getPwd());
        pstat.setString(3, user.getName());
        pstat.setString(4, user.getEmail());
        pstat.setDate(5, new java.sql.Date(user.getBirth().getTime()));
        pstat.setString(6, user.getSns());
        pstat.setTimestamp(7, new java.sql.Timestamp(user.getBirth().getTime()));
        pstat.setString(8, user.getId());

        return pstat.executeUpdate();
    }

    public int deleteUser(String id) throws Exception {
        Connection conn = ds.getConnection();

        String sql = "delete from user_info where id=?";

        PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
        pstat.setString(1, id);
        return pstat.executeUpdate();
    }

    public User selectUser(String id) throws Exception {
        Connection conn = ds.getConnection();

        String sql = "select * from user_info where id=?";

        PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
        pstat.setString(1, id);
        ResultSet rs = pstat.executeQuery(); // select

        if(rs.next()) {
            User user = new User();
            user.setId(rs.getString(1));
            user.setPwd(rs.getString(2));
            user.setName(rs.getString(3));
            user.setEmail(rs.getString(4));
            user.setBirth(new Date(rs.getDate(5).getTime()));
            user.setSns(rs.getString(6));
            user.setReg_date(new Date(rs.getDate(7).getTime()));

            return user;
        }

        return null;
    }

    private void deleteAll() throws Exception {
        Connection conn = ds.getConnection();

        String sql = "delete from user_info";

        PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
        pstat.executeUpdate(); // insert, delete, update
    }

    @Test
    public void transactionTest() throws Exception {
        Connection conn=null;
        try {
            deleteAll();
            conn = ds.getConnection();
            conn.setAutoCommit(false); // conn.setAutoCommit(true);

//        insert into user_info (id, pwd, name, email, birth, sns, reg_date)
//        values ('asdf22', '1234', 'smith', 'aaa@aaa.com', '2021-01-01', 'facebook', now());

            String sql = "insert into user_info values (?, ?, ?, ?, ?, ?, now())";

            PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
            pstat.setString(1, "asdf");
            pstat.setString(2, "1234");
            pstat.setString(3, "abc");
            pstat.setString(4, "aaa@aaa.com");
            pstat.setDate(5, new java.sql.Date(new Date().getTime()));
            pstat.setString(6, "fb");

            int rowCnt = pstat.executeUpdate(); // insert, delete, update

            pstat.setString(1, "asdf");
            rowCnt = pstat.executeUpdate();

            conn.commit();
        } catch (Exception e) {
            conn.rollback();
            e.printStackTrace();
        } finally {
        }
    }

    // 사용자 정보를 user_info 테이블에 저장하는 메서드
    public int insertUser(User user) throws Exception {
        Connection conn = ds.getConnection();

//        insert into user_info (id, pwd, name, email, birth, sns, reg_date)
//        values ('asdf22', '1234', 'smith', 'aaa@aaa.com', '2021-01-01', 'facebook', now());

        String sql = "insert into user_info values (?, ?, ?, ?, ?, ?, now())";

        PreparedStatement pstat = conn.prepareStatement(sql); // SQL Injection공격, 성능향상
        pstat.setString(1, user.getId());
        pstat.setString(2, user.getPwd());
        pstat.setString(3, user.getName());
        pstat.setString(4, user.getEmail());
        pstat.setDate(5, new java.sql.Date(user.getBirth().getTime()));
        pstat.setString(6, user.getSns());

        int rowCnt = pstat.executeUpdate(); // insert, delete, update

        return rowCnt;
    }

    @Test
    public void springJdbcConnectionTest() throws Exception {
//        ApplicationContext ac = new GenericXmlApplicationContext("file:src/main/webapp/WEB-INF/spring/**/root-context.xml");
//        DataSource ds = ac.getBean(DataSource.class);

        Connection conn = ds.getConnection(); // 데이터베이스의 연결을 얻는다.

        System.out.println("conn = " + conn);
        assertTrue(conn!=null); // 괄호 안의 조건식이 true면 테스트 성공, 아니면 실패
    }
}