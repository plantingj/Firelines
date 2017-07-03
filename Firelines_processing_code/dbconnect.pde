void database_connect() {
  if (readyForNew) {
    nrOfRowsNew = db_empty_check();
    if (nrOfRowsNew > nrOfRows) {
      db_get_data();
      readyForNew = false;
    }
  }
}

int db_empty_check() {
  if ( dbconnection.connect() ) {
    dbconnection.query( "SELECT COUNT(*) FROM Nederland");
    dbconnection.next();
    if ((dbconnection.getInt(1) == 0)&&(!empty)) {
      idprio.clear();
      location.clear();
      first=true;
    }
  }
  return dbconnection.getInt(1);
}

void db_get_data() {
  dbconnection.query( "SELECT * FROM Nederland" );
  while (dbconnection.next()) {
    id = dbconnection.getInt("id");
    if ((id==1) && (first)) {
      empty=false;
      location.add(new PVector(map(dbconnection.getInt("rdx"), rdMinX, rdMaxX, 0, 3500), map(dbconnection.getInt("rdy"), rdMaxY, rdMinY, 0, 4200)));
      idprio.add(new PVector(dbconnection.getInt("id"), dbconnection.getInt("prio")));
      first = false;
    } 
    if ((id>idprio.get(idprio.size()-1).x)&&(idprio.size() != 0)) {
      //println("id: " + id + "\tnrOfRows: "+nrOfRows);
      //println("DEBUG: " + id);
      previous = new PVector(location.get(id-2).x, location.get(id-2).y);
      location.add(new PVector(map(dbconnection.getInt("rdx"), rdMinX, rdMaxX, 0, 3500), map(dbconnection.getInt("rdy"), rdMaxY, rdMinY, 0, 4200)));
      idprio.add(new PVector(dbconnection.getInt("id"), dbconnection.getInt("prio")));
    } else {
      // connection failed !
    }
  }
}