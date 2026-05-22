package com.fastcampus.ch3;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.datasource.DataSourceUtils;
import org.springframework.stereotype.Repository;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@Repository
public class B1Dao {
    @Autowired
    DataSource ds;

    public int insert(int key, int value) throws Exception {
        Connection conn = null;
        PreparedStatement pstat = null;

        try {
//            conn = ds.getConnection();
            conn = DataSourceUtils.getConnection(ds);
            System.out.println("conn = " + conn);
            pstat = conn.prepareStatement("insert into b1 values(?,?)");
            pstat.setInt(1, key);
            pstat.setInt(2, value);

            return pstat.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            throw e;
        } finally {
//            close(conn, pstat);
            close(pstat);
            DataSourceUtils.releaseConnection(conn, ds);
        }
    }

    private void close(AutoCloseable... acs) {
        for(AutoCloseable ac:acs) {
            try {
                if(ac!=null) ac.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void deleteAll() throws Exception {
        Connection conn = ds.getConnection();
        String sql = "delete from b1";
        PreparedStatement pstat = conn.prepareStatement(sql);
        pstat.executeUpdate();
        close(pstat);
    }
}
